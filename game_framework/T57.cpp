// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T57.h"

//////////////////////////////

T57::
T57(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T57::getFieldType(){ 
  return tT57; 
}
