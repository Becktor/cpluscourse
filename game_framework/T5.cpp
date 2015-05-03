

#include "game.h"
#include "field.h"
#include "T5.h"

//////////////////////////////


T5::T5(ISceneManager* smgr,
	IVideoDriver* driver,
	int x, int y, playground pg)
	: Floor(smgr, driver, x, y, pg) // calling constructor of parent class
{
	// use a different standard texture than parent class:
	block->setVisible(false);
	timeSpentHere = 0.f; // see below
	falling = false;     // see below
}


void fallThroughHole(Sphere & s, position2di mousemove, f32 frameDeltaTime, f32 friction){
	// This handler would accelerate the sphere downwards, ignoring all
	// mouse movements or speed in horizontal directions:
	vector3df p = s.getPosition();
	vector3df v = s.getVelocity();
	v.X = v.Z = 0.f;
	v.Y -= 1.f*frameDeltaTime; // falling;
	p += v;
	s.setPosition(p);
	s.setVelocity(v);
}

// This method gets called whenever the sphere is on the floor for frameDeltaTime
void T5::handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime){
	falling = true;
	block->setVisible(false);

	s.installAlternateSphereProgress(fallThroughHole);
	

	// We always call the standardSphereProgress -- even after the 3.f
	// seconds, because that will invoke either the standard progress or
	// the alternative handler once it is installed.
	s.standardSphereProgress(mousemove, frameDeltaTime, stdfriction);
};

fieldtype T5::getFieldType(){ return tT5; }


