###############################################################
# Program:
#     Milestone 08, Skeet
#     Brother Comeau, CS165
# Author:
#     Nathan Tagg
# Summary:
#		This is the Skeet game! shoot dem' birds but watch out for the sacred bird!. play to your hearts' content.
# Above and Beyond
#     I added a fast - moving Lander bird with high health that flashes as you hit it. Killing this bird awards lots of points
#		I added a 'freezeBullets' function that stops all bullets on the screen in their tracks. turning them into land mines. (press 'v')
#		I added a 'seek' function that makes any bullets near the bird follow it at a constant (not accelerating) rate. (Hold down the down arrow)
#		I tweaked the ToughBird so that the number is colorfull and not boring. I also randomized the Tough Bird's health from 3 - 6 instead of just 3.
#		I made it so that the gun has spread, instead of just firing straight. making the game more challenging.
#		I made the bullets be rasta colors... But they kindof just look like skittles.
#		I made the birds be spawned at random Y values, and I made it so that they fly in patterns rather than just straight.
###############################################################

OS := $(shell uname)
ifeq ($(OS),Darwin)
	LFLAGS = -framework GLUT -framework OpenGL
else
	LFLAGS = -lglut -lGLU -lGL
endif

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingObject.o birds.o normalBird.o sacredBird.o lander.o bullet.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingObject.o birds.o normalBird.o sacredBird.o lander.o bullet.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h velocity.h rifle.h bullet.h birds.h flyingObject.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

flyingObject.o: flyingObject.cpp flyingObject.h
	g++ -c flyingObject.cpp

birds.o: birds.cpp flyingObject.h
	g++ -c birds.cpp

sacredBird.o: sacredBird.cpp birds.h flyingObject.h
	g++ -c sacredBird.cpp

normalBird.o: normalBird.cpp birds.h flyingObject.h
	g++ -c normalBird.cpp

lander.o: lander.cpp birds.h flyingObject.h
	g++ -c lander.cpp

bullet.o: bullet.cpp flyingObject.h

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
