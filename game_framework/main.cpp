#include <iostream>
#include <fstream>
#include "game.h"
#include "field.h"
//#include "testfield.h"

/* Include the header that includes all student headers */
#include "group-headers.h"

io::path texturepath="enigma3d.app/Contents/Resources/";

class MyEventReceiver : public IEventReceiver
{
public:
  core::position2di Position;
  virtual bool OnEvent(const SEvent& event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
      {
	switch(event.MouseInput.Event)
	  {
	  case EMIE_MOUSE_MOVED:
	    Position.X = event.MouseInput.X;
	    Position.Y = event.MouseInput.Y;
	    break;
	    
	  default:
	    break;
	  }
      }    
    return false;
  }
  virtual bool IsKeyDown(EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }
  MyEventReceiver()
  {
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  } 
private:
  bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

// This function is called by the main routine when reading the 
// level field to create the respective types of stones:

Field* makefield(int fieldtype, ISceneManager* smgr, IVideoDriver* driver, int i, int j, Field::playground pg){
  switch(fieldtype){
    /*
  case tWall:
    return new Wall(smgr,driver,i,j,pg);
    break;
  case tTestWall:
    return new TestWall(smgr,driver,i,j,pg);
    break;
  case tFloor:
    return new Floor(smgr,driver,i,j,pg);
    break;
  case tLightFloor: 
    return new LightFloor(smgr,driver,i,j,pg);
    break;
    */
/* includes a case for each student group */
#include "group-case.c"

  default:
    cerr << "Undefined field type in level file: " << fieldtype << endl;
    error("");
	return 0;
  }
}
     
int main()
{
  // Initialization of Device, Video Driver and Scene Manager
  video::E_DRIVER_TYPE driverType=video::EDT_OPENGL; 
  MyEventReceiver receiver;  
  IrrlichtDevice* device = createDevice(driverType,
					core::dimension2d<u32>(960, 720), 16, false, false, false, &receiver);
  if (device == 0) return 1; 
  video::IVideoDriver* driver = device->getVideoDriver();
  scene::ISceneManager* smgr = device->getSceneManager();

  // Building the scene.

  // open level file
  ifstream infile;
  infile.open("enigma3d.app/Contents/Resources/field.lvl");
  if (infile.fail()) error("Could not open level file\n");

  // checking the file starts with "Enigma-3D"
  string line;
  infile >> line;
  if (line!="Enigma-3D") error("Illegal Level file: "+line+"\n"); 

  // Playground is a two-dimensional array of pointers to fields:
  Field * playground[dimx][dimy];
  
  // now reading from level file one number for each field
  // and creating a wall or floor of the appropriate sub-class
  for(int j=0; j<dimy; j++){
    for(int i=0; i<dimx; i++){
      // determine filed type
      int fieldtype;
      infile >> fieldtype;

      playground[i][j]=makefield(fieldtype,smgr,driver,i,j,playground);
    } 
  } 
  // the level file may contain additional requests for introducing
  // some fields to each other:
  while ((infile >> line), line!="end"){
    // must have the form "introduce x1 y1 to x1 y2"
    if (line!="introduce") error("Level File: mistake in introduce lines");
    int x1,x2,y1,y2;
    infile >> x1 >> y1 >> line >> x2 >> y2;
    if (   (x1 < 0) || x1>=dimx 
	|| (x2 < 0) || x2>=dimx 
        || (y1 < 0) || y1>=dimy 
	|| (y2 < 0) || y2>=dimy 
	|| line !="to" )
      error("Level File: mistake in introduce lines");
    // call the introduceTo method of field x1 y1:
    playground[x1][y1]->introduceTo(*(playground[x2][y2]));
  }
  infile.close();


  Sphere *sphere=new Sphere(smgr,driver);

  scene::ICameraSceneNode* camera=smgr->addCameraSceneNode(NULL,core::vector3df(offsety+50.f,100.f,offsetx),
							        core::vector3df(offsety,0.f,offsetx));
  // to change the camera position use: 
  //    camera->setPosition(core::vector3df(...));
  // see docmentation of  ICameraSceneNode  for more (like setting target, rotation, aspect)

  // hide the mouse cursor
  device->getCursorControl()->setVisible(false);

  // for time measurement: get an initial time reference 
  u32 then = device->getTimer()->getTime();

  // for mouse-move measurement: get an initial mouse position
  core::position2di RefPosition=receiver.Position;

  // compute the field number where the sphere is and notify that field
  int fieldx=getFieldx(sphere->getPosition());
  int fieldy=getFieldy(sphere->getPosition());
  playground[fieldx][fieldy]->sphereEnter(*sphere);

  // Running function introduceSphere for every wall/floor ONCE
  for(int j=0; j<dimy; j++)
    for(int i=0; i<dimx; i++)
      playground[i][j]-> introduceSphere(*sphere); 
	 

  while(device->run())
    {
      if(receiver.IsKeyDown(irr::KEY_KEY_Q)) exit(0); // quit game on key Q
      
      // Adapt speed by the difference in mouse position
      core::position2di mousemove;
      mousemove.X=(receiver.Position.X-RefPosition.X);
      mousemove.Y=(receiver.Position.Y-RefPosition.Y);
      // eliminating too rapid movements of the mouse
      if (fabs((float)mousemove.X)>10) mousemove.X=0;
	  if (fabs((float)mousemove.Y)>10) mousemove.Y = 0;
      // remember current mouse position
      RefPosition=receiver.Position;

      // Measure the time that has passed since last round 
      const u32 now = device->getTimer()->getTime();
      const f32 frameDeltaTime = (f32)(now - then) / 1000.f; 
      then = now;

      /* The field that the sphere is currently on is now in control
	 to decide how the sphere moves within the time
	 frameDeltaTime.  This will typically NOT include collision
	 detection with surrounding walls---that will be done
	 later. */
      playground[fieldx][fieldy]->handleSphere(*sphere,mousemove,frameDeltaTime);

      // tell also all other fields that time has passed:
      for(int j=0; j<dimy; j++)
	for(int i=0; i<dimx; i++)
	  if (i!=fieldx || j!=fieldy)
	    playground[i][j]->timeProgress(frameDeltaTime);

      /* Now we turn to collision detection:
	 - compute what field the sphere is on now
	 - compute overlap with adjacent fields 
	 - notify all fields where overlap is non-zero
      */
      core::vector3df spherePosition = sphere->getPosition();
      int new_fieldx=getFieldx(spherePosition);
      int new_fieldy=getFieldy(spherePosition);

      f32 xoE=getOverlapx(spherePosition,new_fieldx+1);
      f32 xoW=getOverlapx(spherePosition,new_fieldx-1);
      f32 yoN=getOverlapy(spherePosition,new_fieldy+1);
      f32 yoS=getOverlapy(spherePosition,new_fieldy-1);
      // E = east, W = west...
      
      if (xoE) playground[new_fieldx+1][new_fieldy]->sphereOverlap(*sphere,xoE,0.f);
      if (xoW) playground[new_fieldx-1][new_fieldy]->sphereOverlap(*sphere,xoW,0.f);
      if (yoN) playground[new_fieldx][new_fieldy+1]->sphereOverlap(*sphere,0.f,yoN);
      if (yoS) playground[new_fieldx][new_fieldy-1]->sphereOverlap(*sphere,0.f,yoS);
      
      /*
      if (spherePosition==sphere->getPosition()){ 
	// if there was no collision with E,W,N, or S, check for overlaps with diagonal fields
	if (xoE && yoN) playground[new_fieldx+1][new_fieldy+1]->sphereOverlap(*sphere,xoE/4,yoN/4);
	if (xoE && yoS) playground[new_fieldx+1][new_fieldy-1]->sphereOverlap(*sphere,xoE/4,yoS/4);
	if (xoW && yoN) playground[new_fieldx-1][new_fieldy+1]->sphereOverlap(*sphere,xoW/4,yoN/4);
	if (xoW && yoS) playground[new_fieldx-1][new_fieldy-1]->sphereOverlap(*sphere,xoW/4,yoS/4);
      }
      */

      // If all the movements and collisions have changed the field the sphere is on, notify both 
      // the field it leaves and the field it enters: 
      if (new_fieldx!=fieldx || new_fieldy!=fieldy){
	playground[fieldx][fieldy]->sphereExit(*sphere);
	fieldx=new_fieldx;
	fieldy=new_fieldy;
	playground[fieldx][fieldy]->sphereEnter(*sphere);
      }

      // Draw the picture anew and go to a next round
      driver->beginScene(true, true, video::SColor(255,113,113,133));
      smgr->drawAll();
      driver->endScene();
    }
  device->drop();
  return 0;
}
















