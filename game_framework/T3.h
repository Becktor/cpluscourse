/* Example field by Sebastian Moedersheim

T1: Standard Floor

This is really just giving a trivial implementation of Floor: all
that is overloaded from the parent class is the field number (which is
pure virtual in Floor).
*/

#ifndef ____TT3____
#define ____TT3____

#include "game.h"
#include "field.h"

class T3: public Floor
{
public:
  T3(ISceneManager* smgr,
      IVideoDriver* driver,
      int x, int y, playground  pg) ;
  virtual fieldtype getFieldType();
};


#endif
