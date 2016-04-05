#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <math.h>
#include "flyingObject.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;

class Bullet : public FlyingObject
{
private:
	int cor;
	bool seeking;
public:
	Bullet() { alive = true; seeking = false; cor = random(1, 4); };
	void fire(Point pt, float angle) 
	{ 
		point = pt;
		draw(); 
		velocity.setDX(-cos(0.0174533 * (angle + random(-7.0, 7.0))) * 8); 
		velocity.setDY(sin(0.0174533 * (angle +random(-7.0, 7.0))) * 8);
	}
	virtual void draw() 
	{ 
		if (cor == 1)
		{
			drawRedDot(point);
		}
		else if (cor == 2)
		{
			drawYellowDot(point);
		}
		else
		{
			drawGreenDot(point);
		}

	};
};

#endif
