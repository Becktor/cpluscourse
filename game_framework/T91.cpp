// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T91.h"

//////////////////////////////

T91::
T91(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T91::getFieldType(){ 
  return tT91; 
}
