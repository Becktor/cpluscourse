// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T90.h"

//////////////////////////////

T90::
T90(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T90::getFieldType(){ 
  return tT90; 
}
