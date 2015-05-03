// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T13.h"

//////////////////////////////

T13::
T13(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T13::getFieldType(){ 
  return tT13; 
}
