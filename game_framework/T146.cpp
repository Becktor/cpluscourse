// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T146.h"

//////////////////////////////

T146::
T146(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T146::getFieldType(){ 
  return tT146; 
}
