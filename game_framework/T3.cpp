/* Example field by Sebastian Moedersheim

T1: Standard Floor

This is really just giving a trivial implementation of Floor: all
that is overloaded from the parent class is the field number (which is
pure virtual in Floor).
*/

#include "game.h"
#include "field.h"
#include "T3.h"

//////////////////////////////

T3::
T3(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Floor(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T3::getFieldType(){ 
  return tT3; 
}
