#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "uiDraw.h"
#include "birds.h"
#include <math.h>

class SacredBird : public Bird
{
private:

public:

	SacredBird() { health = 1; type = 3; points = -10; speed = random(3, 6); velocity.setDX(speed); }; 
  	virtual void draw() { drawSacredBird(point, size); velocity.addDX(sin(point.getX())); point.addY(sin(point.getX() / random(50, 120))); };

};

#endif
