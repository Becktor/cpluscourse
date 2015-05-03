// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T144.h"

//////////////////////////////

T144::
T144(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T144::getFieldType(){ 
  return tT144; 
}
