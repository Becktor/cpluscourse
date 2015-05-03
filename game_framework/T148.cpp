// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T148.h"

//////////////////////////////

T148::
T148(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T148::getFieldType(){ 
  return tT148; 
}
