// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T136.h"

//////////////////////////////

T136::
T136(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T136::getFieldType(){ 
  return tT136; 
}
