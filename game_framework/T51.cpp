// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T51.h"

//////////////////////////////

T51::
T51(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T51::getFieldType(){ 
  return tT51; 
}
