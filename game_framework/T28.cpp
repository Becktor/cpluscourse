// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T28.h"

//////////////////////////////

T28::
T28(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T28::getFieldType(){ 
  return tT28; 
}
