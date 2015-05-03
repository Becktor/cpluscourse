// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T64.h"

//////////////////////////////

T64::
T64(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T64::getFieldType(){ 
  return tT64; 
}
