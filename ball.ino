//////////////////////////////////////////////////////////////////// DEFINITION OF ALL THE FUNCTIONS IN THE BALL /////////////////////////////////////////////////////////////////////

void Ball::initialise()
{   
  //  THE INITIAL POSITION OF THE BALL AND THE DIRECTION VARIABLE IS BEING ASSIGNED
	position.x = random(0, 7);
	position.y = 0;

	direction.x = random(-1, 2);
	direction.y = 1;
}

void Ball::move(Controller *controller)
{
  
	// THE BALL IS MOVED
	position.x += direction.x;
	position.y += direction.y;

	// WHEN BALL BOUNCES FROM THE SIDE WALLS 
	if (between(position.x, 0, 6) == false)
	{
		position.x = constrain(position.x, 1, 7);
		direction.x *= -1;
	}

	// WHEN BALL REBOUNDS FROM THE TOP WALL 
	if (position.y < 0)
	{
		position.y = 1; 
		direction.y *= -1;
	}

	// WHEN BALL REBOUNDS FROM THE PADDLER
	if (isHitPaddle(controller))
	{
		position.y = 6;
		direction.y *= -1;

		// Get random outward direction
		direction.x = getNewDirection();

		pong.levelUp();
	}

	// WHEN THE PADDLER MISSES THE BAL --->>> GAME OVER
	if (position.y == 7)
	{
		pong.gameOver();
	}
}

bool Ball::isHitPaddle(Controller *controller)
{

        // THE BALL HITS THE PADDLER WHEN ITS Y-COORDINATE EQUALS 6 AND TWO CONDITIONS ARISES -
        // 1) WHEN IT IS JUST ABOVE THE PADDLER
        // 2) HITS DIAGONALLY ON THE EDGES OF THE PADDLER
        //    |         \         /
        // --------  OR  ---------
        
        
	if (position.y == 6)
	{
		if (direction.y == 1)
		{
			if (between(position.x, controller->position.x, (controller->position.x + controller->size) - 1) ||
				between(position.x + direction.x, controller->position.x, (controller->position.x + controller->size) - 1))
			{        
				return true;
			}
		}
	}

	return false;
}

bool Ball::between(int val, int min, int max)
{
	return val >= min && val <= max;
}

int Ball::getNewDirection()
{
	// THE CODE DOESN'T KEEP THE DIRECTION OF THE BALL FIXED IT CHANGES USING THE RANDOM FUNCTION ---- THIS MAKES THE GAME INTERESTING AND MORE ENGAGING.
	int newDirection;

	do 
	{
		newDirection = random(-1, 2);
	} while (newDirection == previousDirection);

	previousDirection = newDirection;

	return newDirection;
}


/////////////////////////////////////////////////////////////////// END OF THE DEFINITION OF THE BALL FUNCTIONS ////////////////////////////////////////////////////////////////////////
