/////////////////////////////////////////////////////////////// DEFINITION OF THE FUNCTIONS OF THE CLASS SPACEINVADERS ///////////////////////////////////////////////////////////

void SpaceInvaders::play()
{
	// SETS THE SIZE OF SHIP
	controller.size = 3;

	// SETS THE POSITION OF THE SHIP
	controller.position.y = 7;

	// SETS THE GAME SPEED
	gameDelay = 50;

	invaderXDirection = 1;
	invaderBounced = 0;

	// LIST CONTAINING ALL THE INVADER
	enemies = LinkedList<point*>();

	// POPULATES THE LEVEL INVADERS
	setupLevel(level);

	invaderStep = millis();
}

void SpaceInvaders::update()
{
	// FIRING PROCESS
	if (controller.rightButtonPressed || controller.leftButtonPressed)
	{
		fire();
	}

	// MOVING THE INVADERS WHEN ITS PROPER TIME -> -> -> -> -> -> -> -> -> -> -> -> -> -> -> ->
	if (millis() - invaderStep > invaderStepDelay)
	{
		invaderStep = millis();

		moveInvaders();
	}

	// UPDATING THE FIRED SHOT
	if (myBullet)
	{
		if (millis() - myBulletStep > myBulletStepDelay)
		{
			myBulletStep = millis();

			myBullet->y--;

			// BULLET OUT THE PLAYING FIELD
			if (myBullet->y < 0)
			{
				free(myBullet);

				myBullet = NULL;
			}
		}
	}

	// UPDATING THE INVADER BULLET------- THERE'S ONLY ONE BULLET RIGHT NOW
	if(invaderBullet)
	{
		if (millis() - invaderBulletStep > enemyBulletStepDelay)
		{
			invaderBulletStep = millis();

			invaderBullet->y++;

			if (invaderBullet->y > 7)
			{
				free(invaderBullet);

				invaderBullet = NULL;
			}
		}
	}
	else
	{
		// WHEN NO BULLET IS THERE ---- LET THERE BE 1 BULLET
		invaderShoot();
	}

	detectCollisions();

	draw();
}

void SpaceInvaders::moveInvaders()
{
	
        /* INVADERS MOVE IN A FORMATION FROM LEFT TO RIGHT DIRECTION AND VICE-VERSA---- WHEN BOUNCED OFF THE 
        SCREEN SIDE WALLS 6 TIMES ---- THEY STEP FORWARD AND REPEAT SO WE SET X AND Y DIRECTIONS */
        
	for (int i = 0; i < enemies.size(); i++)
	{
		point *enemy = enemies.get(i);

		if (enemy->x == 0 || enemy->x == 7)
		{
			invaderBounced++;

			if (invaderBounced % 6 == 0)
			{
				invaderYDirection = 1;

				break;
			}

			invaderXDirection *= -1;

			break;
		}
	}

	// MOVE EACH INVADER IN THE OBTAINED DIRECTION
	for (int i = 0; i < enemies.size(); i++)
	{
		point *enemy = enemies.get(i);

		stepInvader(enemy);
	}

	invaderYDirection = 0;
}

void SpaceInvaders::stepInvader(point *position)
{
	if (invaderYDirection == 0)
	{
		position->x += invaderXDirection;
	}

	position->y += invaderYDirection;
}


void SpaceInvaders::draw()
{
	display.clear();

	drawShip();

	for (int i = 0; i < enemies.size(); i++)
	{
		point *enemy = enemies.get(i);

		display.drawPixel(enemy->x, enemy->y);
	}

	drawBullets();
}

void SpaceInvaders::drawShip()
{
	
	display.draw(&controller);
	display.drawPixel(controller.position.x + 1, controller.position.y - 1);
}

void SpaceInvaders::drawBullets()
{
	if (myBullet)
	{
		display.drawPixel(myBullet->x, myBullet->y);
	}

	if (invaderBullet)
	{
		display.drawPixel(invaderBullet->x, invaderBullet->y);
	}
}

void SpaceInvaders::setupLevel(int lvl)
{
	// LEVEL 1 ----  2 ROWS OF INVADERS
	spawnInvader(0, 1);
	spawnInvader(0, 3);
	spawnInvader(0, 5);
	spawnInvader(1, 2);
	spawnInvader(1, 4);
	spawnInvader(1, 6);

	invaderStepDelay = 750;

	// LEVEL 2 ----- ADD A THIRD ROW
	if (lvl > 1)
	{
		spawnInvader(2, 1);
		spawnInvader(2, 3);
		spawnInvader(2, 5);

		invaderStepDelay = 625;
	}

	// LEVEL 3 ------ ADD ANOTHER ROW
	if (lvl > 2)
	{
		spawnInvader(3, 2);
		spawnInvader(3, 4);
		spawnInvader(3, 6);

		invaderStepDelay = 500;
	}	

	
}

void SpaceInvaders::spawnInvader(int y, int x)
{
	point *position;
	position = (struct point*)malloc(sizeof(struct point));
	position->x = x;
	position->y = y;

	enemies.add(position);
}

void SpaceInvaders::detectCollisions()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		point *enemyPosition = enemies.get(i);

		detectShipCollision(enemyPosition);		
	}

	detectShipCollision(invaderBullet);

	detectEnemyShot(myBullet);

	detectBulletsCollision();
}

void SpaceInvaders::detectBulletsCollision()
{
	if (myBullet->x == invaderBullet->x && myBullet->y == invaderBullet->y)
	{
		free(invaderBullet);
		invaderBullet = NULL;

		free(myBullet);
		myBullet = NULL;
	}
}

void SpaceInvaders::detectEnemyShot(point *position)
{
	if (myBullet)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			point *enemy = enemies.get(i);

			if (myBullet->x == enemy->x && myBullet->y == enemy->y)
			{
				enemies.remove(i);

				free(myBullet);
				myBullet = NULL;

				if (enemies.size() == 0)
				{
					levelUp();
				}
			}
		}
	}
}

void SpaceInvaders::detectShipCollision(point *position)
{
	if (position->x == controller.position.x + 1 && position->y == controller.position.y - 1)
	{
		gameOver();
	}

	if (position->y == controller.position.y &&
		(position->x >= controller.position.x &&
		position->x <= controller.position.x + controller.size - 1))
	{
		gameOver();
	}
}

void SpaceInvaders::gameOver()
{
	display.flashSprite(lost, 4, 500);

	resetGame();

	level = 1;

	menu.initialize();
}

void SpaceInvaders::fire()
{
	if (!myBullet)
	{
		myBullet = (struct point*)malloc(sizeof(struct point));
		myBullet->x = controller.position.x + 1;
		myBullet->y = controller.position.y - 1;

		myBulletStep = millis();
	}
}

void SpaceInvaders::invaderShoot()
{
	// GETS A RANDOM ENEMY
	int invaderIndex = random(enemies.size());

	// FINDS LOWEST ENEMIES TO AVOID SHOOTINF IN THE BACK TEAMIES

	point *lowestEnemy = enemies.get(invaderIndex);

	for (int i = 0; i < enemies.size(); i++)
	{
		point *tempEnemy = enemies.get(i);

		if (tempEnemy->x == lowestEnemy->x && tempEnemy->y > lowestEnemy->y)
		{
			lowestEnemy = tempEnemy;
		}
	}

	// FIRES ------ 

	invaderBullet = (struct point*)malloc(sizeof(struct point));
	invaderBullet->x = lowestEnemy->x;
	invaderBullet->y = lowestEnemy->y;

	invaderBulletStep = millis();
}

void SpaceInvaders::levelUp()
{
	resetGame();

	level++;

	display.flashSprite(up, 3, 500); 

	play();	
}

void SpaceInvaders::resetGame()
{
	// CLEANS UP AFTER OURSELVES

	free(myBullet);
	myBullet = NULL;

	free(invaderBullet);
	invaderBullet = NULL;

	for (int i; i < enemies.size(); i++)
	{
	   point *enemy = enemies.get(i);

	   free(enemy);
	   enemy = NULL;
	}
}
