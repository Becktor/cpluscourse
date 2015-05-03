// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T31.h"

//////////////////////////////

T31::
T31(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T31::getFieldType(){ 
  return tT31; 
}
