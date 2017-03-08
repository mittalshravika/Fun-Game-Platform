///////////////////////////////////////////////////////////////////////////////// DEFINITION OF THE CLASS MENU - ///////////////////////////////////////////////////////////////////

void Menu::initialize()
{
	controller.size = 1;

	currentGame = gmMenu;

	elpased = millis();
}

void Menu::update()
{
  // THE USER WOULD SELECT THE GAME HE WANTS TO PLAY-----THIS WOULD BE DONE BY THE SWITCH STATEME
  
	switch (currentGame)
	{
	case gmMenu:
		updateMenu();
		break;
	case gmPong:
		pong.update();
		break;
	case gmTedshow:
		tedShow.update();
		break;
	case gmSpaceInvaders:
		spaceInvaders.update();
		break;
	case gmSnake:
		snake.update();
		break;
	}
}

void Menu::updateMenu()

        // FIND SPRITES OFFSET ACCORDING TO THE POTENTIONMETER READINGS
	int offset = map(analogRead(ControllerPotPin), 0, 1020, 0, width - 8);

	// DISPLAYS THE SPRITES FROM THE OFFSET
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			display.drawPixel(x, y, menuStrip[y][x + offset] == 1);
		}
	}

	// READS THE PRESSED START BUTTON
	if (controller.rightButtonPressed || controller.leftButtonPressed)
	{
		startGame(offset);
	}
}

void Menu::startGame(int offset)
{
	
        // STARTS THE SELECTED GAME BY THE USER ACCORDING TO THE OFFSET READING IN updateMenu()
        /* The currentGame enum determines which update method will be
	   called in the Menu::update method, which in turn is called in the 
	   loop method.  */

	if (between(offset, 0, 2))
	{
		currentGame = gmPong;
	    
		// NEW GAME ANIMATION IS DISPLAYED
    	display.newGame();
		
		pong.play();
	}

	if (between(offset, 7, 9))
	{
		currentGame = gmTedshow;
	    
		// NEW GAME ANIMATION IS DISPLAYED
    	display.newGame();
		
		tedShow.play();
	}

	if (between(offset, 15, 17))
	{
		currentGame = gmSpaceInvaders;
	    
		// NEW GAME ANIMATION IS DISPLAYED
    	display.newGame();
		
		spaceInvaders.play();
	}

	if (between(offset, 23, 24))
	{    
		currentGame = gmSnake;
	    
		// NEW GAME ANIMATION IS DISPLAYED
    	display.newGame();
		
		snake.play();
	}
}

bool Menu::between(int val, int min, int max)
{
	return val >= min && val <= max;
}
