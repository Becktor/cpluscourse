// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T41.h"

//////////////////////////////

T41::
T41(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T41::getFieldType(){ 
  return tT41; 
}
