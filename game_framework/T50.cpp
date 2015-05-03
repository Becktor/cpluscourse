// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T50.h"

//////////////////////////////

T50::
T50(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T50::getFieldType(){ 
  return tT50; 
}
