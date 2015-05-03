/* Example field by Sebastian Moedersheim

T1: Standard Wall

This is really just giving a trivial implementation of Wall: all
that is overloaded from the parent class is the field number (which is
pure virtual in Wall).
*/

#include "game.h"
#include "field.h"
#include "T1.h"

//////////////////////////////

T1::
T1(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
{
} ;

fieldtype T1::getFieldType(){ 
  return tT1; 
}
