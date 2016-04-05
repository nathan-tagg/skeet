#ifndef BIRDS_H
#define BIRDS_H

#include "flyingObject.h"

class Bird : public FlyingObject
{
protected:
	int size;
	int health;
	int type;
	int points;
	int speed;
public:
	Bird() 
	{ 
		size = random(10, 30);
		velocity.setDX(0); 
		velocity.setDY(0); 
		point.setX(-200); 
		point.setY(random(-40, 160)); 
		alive = true; 
	}
	virtual void draw() {};
	virtual int hit() { return points; };
	int getSize() { return size; };
	int getHealth() { return health; };
	int getType() { return type; };
  	void addHealth(int h) { health = health + h; };

};

#endif
