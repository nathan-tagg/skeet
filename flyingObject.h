#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
protected:
	bool alive;
	Point point;
	Velocity velocity;

public:
	bool isAlive() { return alive; };
	void advance() 
	{ 
		point.addX(velocity.getDX()); 
		point.addY(velocity.getDY());
		draw(); 
	};
	virtual void draw() = 0;
	Point getPoint() { return point; };
	Velocity getVelocity() { return velocity; };
	void setVelocity(Velocity v) { velocity = v; };
	void setVelocity(float x, float y) { velocity.setDX(x); velocity.setDY(y); };
	void addVelocity(float x, float y) { velocity.addDX(x); velocity.addDY(y); };
	void kill() { alive = false; };
};


#endif