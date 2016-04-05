#ifndef LANDER_H
#define LANDER_H

#include "birds.h"
#include "uiDraw.h"

class Lander : public Bird
{
private:

public:
	Lander() { health = 15; type = 4; points = 2; speed = random(3, 6); velocity.setDX(speed); };
	virtual void draw() 
	{ 
		drawLander(point); 
		if (point.getX() > -160)
		{
			point.addX( 10 * cos(point.getX() / 75));
			point.addY( 3 * sin(point.getX() / 75)); 
			velocity.addDX(cos(point.getX()));
		}
	};
	virtual int hit() { drawRedLander(point); return 1; };

};

#endif