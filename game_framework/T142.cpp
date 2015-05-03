// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T142.h"

//////////////////////////////

T142::
T142(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T142::getFieldType(){ 
  return tT142; 
}
