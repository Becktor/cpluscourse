/* Example field by Sebastian Moedersheim

T1: Standard Wall

This is really just giving a trivial implementation of Wall: all
that is overloaded from the parent class is the field number (which is
pure virtual in Wall).
*/
 
#ifndef ____TT1____
#define ____TT1____

#include "game.h"
#include "field.h"

class T1: public Wall 
{
public:
  T1(ISceneManager* smgr,
      IVideoDriver* driver,
      int x, int y, playground  pg) ;
  virtual fieldtype getFieldType();
};


#endif
