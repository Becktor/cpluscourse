// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T84.h"

//////////////////////////////

T84::
T84(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T84::getFieldType(){ 
  return tT84; 
}
