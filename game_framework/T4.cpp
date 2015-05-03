/* Example field by Sebastian Moedersheim

T4: Light Floor 

This floor will break out if the sphere is on it for too long. When it
breaks, it takes over the control of the sphere so that it goes into a
free fall.

*/
 
#include "game.h"
#include "field.h"
#include "T4.h"

//////////////////////////////


T4::T4(ISceneManager* smgr,
	IVideoDriver* driver,
		       int x, int y, playground pg) 
  : Floor(smgr,driver,x,y,pg) // calling constructor of parent class
{
  // use a different standard texture than parent class:
  texture=driver->getTexture(texturepath+"fl-bridgex-closed.png");
  block->setMaterialTexture(0,texture); 

  // use a alternative texture (for when the sphere is on this Floor).
  alt_texture=driver->getTexture(texturepath+"fl-plank.png");

  timeSpentHere=0.f; // see below
  falling=false;     // see below
}

// when the sphere enters, change the texture to the alternate one
void T4::sphereEnter(Sphere &s){
  block->setMaterialTexture(0,alt_texture); 
}

// change back when the sphere leaves.
void T4::sphereExit(Sphere &s){
  block->setMaterialTexture(0,texture);
}

/* Example for the feature to install a special "handler" for the
   sphere (that is independent of the Floor the sphere is on). Then we
   first have to declare a function that has just the same input
   arguments as the following one (and no output):  */

void fallingSphere(Sphere & s,position2di mousemove,f32 frameDeltaTime,f32 friction){
  // This handler would accelerate the sphere downwards, ignoring all
  // mouse movements or speed in horizontal directions:
  vector3df p=s.getPosition();
  vector3df v=s.getVelocity();
  v.X=v.Z=0.f;
  v.Y-=1.f*frameDeltaTime; // falling;
  p+=v;
  s.setPosition(p);
  s.setVelocity(v);
}  

// This method gets called whenever the sphere is on the floor for frameDeltaTime
void T4::handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime){
  // We count the total time that the sphere has been on this field:
  timeSpentHere+=frameDeltaTime;

  // If we have spent more than 3.0 time units here, then the floor is
  // removed and the sphere falls downwards. The falling flag is used
  // so that we won't start falling more than once.
  if (!falling && timeSpentHere>3.f){
    falling =true;
    // removing the floor by making it invisble:
    block->setVisible(false);

    // Installing the "fallingSphere" handler we have defined
    // above. The sphere will no longer behave according to the
    // standardSphereProgress-method (of class sphere) but do what the
    // fallingSphere handler tells it to. Note that we here give the
    // entire "fallingSphere" function as an argument (!) to the
    // installAlternateSphereProgress method.
    s.installAlternateSphereProgress(fallingSphere);
  }

  // We always call the standardSphereProgress -- even after the 3.f
  // seconds, because that will invoke either the standard progress or
  // the alternative handler once it is installed.
  s.standardSphereProgress(mousemove, frameDeltaTime, stdfriction);
};

fieldtype T4::getFieldType(){ return tT4; }


