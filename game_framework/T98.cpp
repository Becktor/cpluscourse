// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T98.h"

//////////////////////////////

T98::
T98(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T98::getFieldType(){ 
  return tT98; 
}
