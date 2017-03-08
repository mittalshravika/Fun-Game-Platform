 //////////////////////////////////////////////////////// THE FUNCTIONS OF CLASS PONG ARE BEING DEFINED AS FOLLOWS - //////////////////////////////////////////////////////////////


void Pong::play()
{
  gameDelay = 200;
  
  controller.size = ControllerSize;
  
  controller.position.y = 7;
  
  level = 0;
  
  // The bumpers will act as obstacles and rebound the ball 
  point bumperLeft;
  bumperLeft.x = 2;
  bumperLeft.y = 3;
  
  bumpers[0] = bumperLeft;

  point bumperRight;
  bumperRight.x = 5;
  bumperRight.y = 3;
 
  bumpers[1] = bumperRight;
  
  // Bumpers are activated in LEVEL NO. 3
  nofBumpers = 0;
  
  ball.initialise();  
}

void Pong::update()
{
  for(int i = 0; i < nofBumpers; i++)
  {
    updateBumpers(bumpers[i], &ball);
  }
 
  ball.move(&controller);

  display.clear();
  display.draw(&pong.ball);
  display.draw(&controller);
  
  for(int i = 0; i < nofBumpers; i++)
  {
    display.drawPixel(bumpers[i].x, bumpers[i].y);
  }
}

void Pong::Game_Over()
{ 
  display.flashSprite(lost, 4, 500); 
  
  menu.initialize();  
}

void Pong::level_increment()
{
  level++;
   
  if (level % 10 == 0)  ////// THE SPPED OF THE GAME INCREASES AFTER EACH 10 HITS.
  {
    display.flashSprite(up, 3, 500); 
 
	// Game needs to be made faster now
    gameDelay -= 30;
    
	// Now Decrease the size of pddler and make it difficult for the player
    if (gameDelay < 120)
    {
      controller.size--;
      
      if (controller.size == 0)
      {
        menu.initialize();
      }
      
      gameDelay = 200;
    }
    
	// Add the respective bumpers in the game when the time comes
    nofBumpers = gameDelay < 150 ? 2 : 0;
    
    ball.initialise();
  }
}

void Pong::updateBumpers(point bumper, Ball *ball)
{
    if (ball->position.x == bumper.x && ball->position.y == bumper.y)
  {
    int new_posx= -1 * ball->direction.x;
    
    if (ball->direction.x == 0 && ball->direction.y == 1)
    {
      new_posx= random(2) == 0 ? -1 : 1;
    }
    
    ball->direction.x = newX;
    ball->direction.y *= -1;
  }
}

////////////////////////////////////////////////////////////////////////// END OF PONG CLASS DEFINITION ////////////////////////////////////////////////////////////////////////////
