/* Example field by Sebastian Moedersheim

T4: Light Floor 

This floor will break out if the sphere is on it for too long. When it
breaks, it takes over the control of the sphere so that it goes into a
free fall.

*/
 
#ifndef ____TT4____
#define ____TT4____

#include "game.h"
#include "field.h"

class T4: public Floor
{
protected:
  // this one contains a second texture (for when the sphere is on this floor)
  ITexture *alt_texture;

  // a counter for the time that the sphere was on this floor
  f32 timeSpentHere;

  // a flag whether the sphere is in free fall mode
  bool falling;
public:
  T4(ISceneManager* smgr,
      IVideoDriver* driver,
      int x, int y, playground  pg) ;
  virtual fieldtype getFieldType();
  virtual void sphereEnter(Sphere &s);
  virtual void sphereExit(Sphere &s);
  virtual void handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime);
};

#endif
