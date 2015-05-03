// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T76.h"

//////////////////////////////

T76::
T76(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T76::getFieldType(){ 
  return tT76; 
}
