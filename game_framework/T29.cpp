// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T29.h"

//////////////////////////////

T29::
T29(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T29::getFieldType(){ 
  return tT29; 
}
