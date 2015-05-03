/* Example field by Sebastian Moedersheim

T2: Destructable Wall

This wall will destruct when hit by the sphere. It also allows to be connected to other walls of the same type (see the "connect" lines in the example level: field.lvl)

*/

#ifndef ____TT6____
#define ____TT6____

#include "game.h"
#include "field.h"

class T6 : public Floor// if you implement a Floor tile, replace "Wall" with "Floor"
{
protected:
	// To demonstrate the "introduceTo" feature, we have here a pointer to another
	// field of type T2. (Explained in comments where it is used)
	T6 *warpDestination;
	ITexture *alt_texture;
	float xpos;
	float ypos;
public:
	T6(ISceneManager* smgr,
		IVideoDriver* driver,
		int x, int y, playground  pg);
	virtual fieldtype getFieldType();
	virtual void introduceTo(Field &f);
	virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);
};


#endif
