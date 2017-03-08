////////////////////////////////////////////////////////////// THE DEFINITION OF THE FUNCTIONS OF THE CLASS SNAKE ///////////////////////////////////////////////////////////////////


void Snake::play()
{
	snakeStepElapsed = millis();
	snakeStepDelay = 750;

	// THE BELOW CODES MAKES UP THE SNAKE
	segments = LinkedList<point*>();
	segments.add(spawnSegment(4,4));
	segments.add(spawnSegment(5,4));
	segments.add(spawnSegment(6,4));
	segments.add(spawnSegment(7,4));

	direction.x = -1;
	direction.y = 0;


	// SETS THE BAIT
	setApple();

	addSegment = false;

	// DEPARTS IN A STRAIGHT LINE 
	steer = stCentre;
}

void Snake::update()
{
	// READ CONTROLLER BUTTONS
	if (controller.leftButtonPressed)
	{
		steer = stLeft;
	}

	if (controller.rightButtonPressed)
	{
		steer = stRight;
	}

	detectCollisions();

	// TIME TO STEP
	if (millis() - snakeStepElapsed > snakeStepDelay)
	{
		snakeStepElapsed = millis();

		move();

		
		steer = stCentre;

		draw();		
	}	
}

void Snake::detectCollisions()
{
	point* head = segments.get(0);

	// CHECKS THE DISPLAY BOUNDARIES
	if (head->x < 0 || head->x > 7 || head->y < 0 || head->y > 7)
	{
		gameOver();
	}

	// CHECKS THE BITING ITSELF
	for (int i = 1; i < segments.size(); i++)
	{
		point* segment = segments.get(i);

		if (segment->x == head->x && segment->y == head->y)
		{
			gameOver();
		}
	}

	// CHECKS APPLE
	if (head->x == apple.x && head->y == apple.y)
	{
		addSegment = true;

		// SPPED INCREASES
		snakeStepDelay -= 15;

		// NEW APPLES GENERATED
		setApple();
	}

	
}

void Snake::draw()
{
	display.clear();

	// DRAWS THE SNAKE
	for (int i = 0; i < segments.size(); i++)
	{
		point *segment = segments.get(i);

		display.drawPixel(segment->x, segment->y);
	}

	// DRWAS THE APPLE
	display.drawPixel(apple.x, apple.y);
}

void Snake::move()
{
        SET NEW DIRECTION IF LEFT OR RIGHT BUTTON WAS PRESS
	int dX = direction.x;
	int dY = direction.y;

	if (steer == stLeft)
	{
		direction.x = dY;
		direction.y = -dX;
	}

	if (steer == stRight)
	{
		direction.x = -dY;
		direction.y = dX;
	}


	// KEEP LAST SEGMENT IN MEMORY IF THE LAST APPLE HAD BEEN EATEN
	int lastX;
	int lastY;

	if (addSegment)
	{
		point* last = segments.get(segments.size() -1);
		lastX = last->x;
		lastY = last->y;
	}

	
	for (int i = segments.size() - 1; i > 0; i--)
	{
		point *old = segments.get(i);
		free(old);	

		point *next = segments.get(i-1);


		point *segment = spawnSegment(next->x, next->y);

		segments.set(i, segment);
	}

	
	if (addSegment)
	{
		segments.add(spawnSegment(lastX, lastY));

		addSegment = false;
	}

	// MOVE HEAD SEGMENT ACCORDING TO THE CURRENT DIRECTION
	point *head = segments.get(0);

	segments.set(0, spawnSegment(head->x + direction.x, head->y + direction.y));
}

point* Snake::spawnSegment(int x, int y)
{
	point *position;
	position = (struct point*)malloc(sizeof(struct point));
	position->x = x;
	position->y = y;

	return position;
}

void Snake::setApple()
{
	int x;
	int y;

	bool ok = true;

	// FINDS AN UNOCCUPIED SPOT
	do
	{
		x = random(0, 8);
		y = random(0, 8);

		ok = true;

		for (int i = 0; i < segments.size()-1; i++)
		{
			point* segment = segments.get(i);

			if (segment->x == x && segment->y == y)
			{
				ok = false;
				break;
			}
		}

	} while (!ok);

	apple.x = x;
	apple.y = y;
}

void Snake::gameOver()
{
	
	segments.clear();


	display.flashSprite(lost, 4, 500);

	
	menu.initialize();
}
