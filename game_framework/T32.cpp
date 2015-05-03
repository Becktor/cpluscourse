// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T32.h"

//////////////////////////////

T32::
T32(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T32::getFieldType(){ 
  return tT32; 
}
