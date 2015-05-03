// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T21.h"

//////////////////////////////

T21::
T21(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T21::getFieldType(){ 
  return tT21; 
}
