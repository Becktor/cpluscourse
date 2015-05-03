// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T34.h"

//////////////////////////////

T34::
T34(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T34::getFieldType(){ 
  return tT34; 
}
