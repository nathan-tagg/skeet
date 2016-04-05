#ifndef NORMALBIRD_H
#define NORMALBIRD_H

#include "birds.h"

class NormalBird : public Bird
{
private:

public:
	NormalBird() { health = 1; type = 1; points = 1; speed = random(3, 8); velocity.setDX(speed); };
  	virtual void draw() { drawCircle(point, size); velocity.addDX(sin(point.getX())); point.addY(sin(point.getX() / random(50, 120))); };
};

#endif