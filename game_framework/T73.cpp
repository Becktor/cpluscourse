// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T73.h"

//////////////////////////////

T73::
T73(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T73::getFieldType(){ 
  return tT73; 
}
