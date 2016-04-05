#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "birds.h"

class ToughBird : public Bird
{
public:
	ToughBird() { health = random(3, 6); type = 2; points = 1; speed = random(2, 4); velocity.setDX(speed); };
	virtual void draw() { drawToughBird(point, size, health); velocity.addDX(sin(point.getX())); point.addY(sin(point.getX() / random(50, 120))); };
};

#endif
