////////////////////////////////////////////////////////////////////////// WRAP UP OF THE WHOLE CODE //////////////////////////////////////////////////////////////////////////////////

#define ControllerSize 3
#define ControllerPotPin A0
#define ControllerRightButtonPin 4S
#define ControllerLeftButtonPin 5
#define DIN 12
#define CLK 11
#define CS 10
#define MenuWidth 32
#define MenuHeight 8
 
/////////////////////////////////////////////////////////////////////// IMPORTING ALL THE HEADER FILES TO BE USED ////////////////////////////////////////////////////////////////////////
 
#include "LinkedList.h"
#include "LedControl.h"
#include "types.h"
#include "sprites.h"
#include "menu.h"
#include "controller.h"
#include "ball.h"
#include "display.h"
#include "pong.h"
#include "tedShow.h"
#include "SpaceInvaders.h"
#include "Snake.h"

Pong pong;
Controller controller;
Display display;    
Menu menu;
TedShow tedShow;
SpaceInvaders spaceInvaders;
Snake snake;

long gameDelay = 10;
long elapsed;

void setup() 
{
	Serial.begin(9600);

	randomSeed(analogRead(0));

	menu.initialize();
}

void loop() 
{
	controller.update();	

	if (millis() - elapsed > gameDelay)
	{
		elapsed = millis();		

		menu.update();
	}
}

//////////////////////////////////////////////////////////////////////////// END OF THE WRAP-UP ///////////////////////////////////////////////////////////////////////////////////////
