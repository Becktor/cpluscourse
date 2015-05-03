// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T18.h"

//////////////////////////////

T18::
T18(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T18::getFieldType(){ 
  return tT18; 
}
