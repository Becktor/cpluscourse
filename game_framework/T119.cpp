// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T119.h"

//////////////////////////////

T119::
T119(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T119::getFieldType(){ 
  return tT119; 
}
