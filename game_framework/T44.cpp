// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T44.h"

//////////////////////////////

T44::
T44(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T44::getFieldType(){ 
  return tT44; 
}
