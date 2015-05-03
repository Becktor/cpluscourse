/* Example field by Sebastian Moedersheim

T2: Destructable Wall

This wall will destruct when hit by the sphere. It also allows to be connected to other walls of the same type (see the "connect" lines in the example level: field.lvl)

*/

#include "game.h"
#include "field.h"
#include "T2.h"

//////////////////////////////

fieldtype T2::getFieldType(){ 
  return tT2; 
}

T2::T2(ISceneManager* smgr,
	   IVideoDriver* driver,
	   int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling constructor of parent class
{
  // use a different texture than parent class:
  texture=driver->getTexture(texturepath+"st-rock3_cracked.png");
  block->setMaterialTexture(0,texture); 
  // A pointer to a related object which is initially 0 (i.e. no
  // related object).
  related=0;
} ;

void T2::introduceTo(Field &f){
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
  if (f.getFieldType()!=tT2) error("T2 introduced to a Non-T2!!\n");
  printf("%i",f.getx());
  // Now we know that f is an object of type T2 (i.e. a more
  // specific type than Field). We do a pointer conversion, so we can
  // store it in the variable "related" (which is of type
  // T2*). So this field can later communicate to the related Field.
  related=(T2 *) &f;
}

void T2::sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap){

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

  if (x>0 && pg[x-1][y]->getFieldType()==tT2){
    ((T2 *)pg[x-1][y])->block->setVisible(false);
  }
  if (y>0 && pg[x][y-1]->getFieldType()==tT2){
    ((T2 *)pg[x][y-1])->block->setVisible(false);
  }
  if (x<dimx-1 && pg[x+1][y]->getFieldType()==tT2){
    ((T2 *)pg[x+1][y])->block->setVisible(false);
  }
  if (y<dimy-1 && pg[x][y+1]->getFieldType()==tT2){
    ((T2 *)pg[x][y+1])->block->setVisible(false);
  }

  /* Another example: if the introduceTo function above had been
     called for this field, i.e. if the pointer "related" is not 0,
     then we set that related field to be visible again. */
     
  if (related)
    related->block->setVisible(true);

  // standard collision detection (a copy of the code parent class)
  vector3df p=s.getPosition();
  vector3df v=s.getVelocity();
  if (xoverlap!=0){ 
    v.Z= -v.Z; 
    p.Z += 2*xoverlap; 
  }
  if (yoverlap!=0){
    v.X= -v.X; 
    p.X += 2*yoverlap; 
  }
  s.setPosition(p);
  s.setVelocity(v);
}

