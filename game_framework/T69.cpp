// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T69.h"

//////////////////////////////

T69::
T69(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T69::getFieldType(){ 
  return tT69; 
}
