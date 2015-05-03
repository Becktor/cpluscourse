/* Example field by Sebastian Moedersheim

T2: Destructable Wall

This wall will destruct when hit by the sphere. It also allows to be connected to other walls of the same type (see the "connect" lines in the example level: field.lvl)

*/

#include "game.h"
#include "field.h"
#include "T6.h"

//////////////////////////////

fieldtype T6::getFieldType(){
	return tT6;
}

T6::T6(ISceneManager* smgr,
	IVideoDriver* driver,
	int x, int y, playground pg)
	: Floor(smgr, driver, x, y, pg)
	// calling constructor of parent class
{
	// use a different texture than parent class:
	texture = driver->getTexture(texturepath + "portal2.png");
	alt_texture = driver->getTexture(texturepath + "portal1.png");
	block->setMaterialTexture(0, texture);
	// A pointer to a related object which is initially 0 (i.e. no
	// related object).
	warpDestination = 0;
	xpos = 8.5;
	ypos = 8.5;
};


void T6::introduceTo(Field &f){
	/* Example to how to build up relationships between fields.
	The field.lvl file contains the line

	introduce 14 2 to 1 7

	which means that main routine is going to call

	playground[14][2]->introduceTo(playground[1][7]);

	We assume that such calls only occur for fieldtypes that "know
	how to talk to each other" (i.e. being programmed by the same
	team). In the example, let's say it can only happen between
	objects of type T2. And we first check this:
	*/
	if (f.getFieldType() != tT6) error("T6 introduced to a Non-T6!!\n");
	xpos = xpos * f.getx();
	ypos = ypos * f.gety();
	if (xpos != 8.5){
		block->setMaterialTexture(0, alt_texture);
	}
	// Now we know that f is an object of type T2 (i.e. a more
	// specific type than Field). We do a pointer conversion, so we can
	// store it in the variable "related" (which is of type
	// T2*). So this field can later communicate to the related Field.

	warpDestination = (T6 *)&f;
}
void T6::sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap){

	/* This function is called when the sphere touches/overlaps with the
	borders of this T2. Normally we do just collision detection
	(as in the parent class Wall), but here wo do something additional:

	We make an example of using the playground (which is a parameter
	of the constructor for all Fields). Here we check whether any of
	the adjacent Fields is also of type T2; if so, we make it
	invisible. For that we first need a pointer conversion from
	(Field *) to the more specific (T2 *) -- because Field does
	not have a member variable "block" that we want to access.
	*/
	if (xpos != 8.5){
		
	vector3df p = s.getPosition();
	vector3df d = vector3df(ypos, p.Y, xpos);
	if (x>0 && pg[x - 1][y]->getFieldType() == tT6){
		s.setPosition(d);
	}
	if (y>0 && pg[x][y - 1]->getFieldType() == tT6){
		s.setPosition(d);
	}
	if (x<dimx - 1 && pg[x + 1][y]->getFieldType() == tT6){
		s.setPosition(d);
	}
	if (y<dimy - 1 && pg[x][y + 1]->getFieldType() == tT6){
		s.setPosition(d);
	}
	s.setPosition(d);
	}
	/* Another example: if the introduceTo function above had been
	called for this field, i.e. if the pointer "related" is not 0,
	then we set that related field to be visible again. */



}