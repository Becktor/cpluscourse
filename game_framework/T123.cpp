// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T123.h"

//////////////////////////////

T123::
T123(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T123::getFieldType(){ 
  return tT123; 
}
