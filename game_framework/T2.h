/* Example field by Sebastian Moedersheim

T2: Destructable Wall

This wall will destruct when hit by the sphere. It also allows to be connected to other walls of the same type (see the "connect" lines in the example level: field.lvl)

*/

#ifndef ____TT2____
#define ____TT2____

#include "game.h"
#include "field.h"

class T2: public Wall // if you implement a Floor tile, replace "Wall" with "Floor"
{
protected:
  // To demonstrate the "introduceTo" feature, we have here a pointer to another
  // field of type T2. (Explained in comments where it is used)
  T2 *related;
public:
  T2(ISceneManager* smgr,
      IVideoDriver* driver,
      int x, int y, playground  pg) ;
  virtual fieldtype getFieldType();
  virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);
  virtual void introduceTo(Field &f);
};


#endif
