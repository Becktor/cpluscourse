// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T60.h"

//////////////////////////////

T60::
T60(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T60::getFieldType(){ 
  return tT60; 
}
