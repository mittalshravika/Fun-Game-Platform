//////////////////////////////////////////////// DEFINITION OF THE CLASS SPACE-INVADERS //////////////////////////////////////////////////////

class SpaceInvaders
{
  private:
	
  // PRIVATE DATA MEMBERS
    LinkedList<point*> enemies;
    int level = 1;
    point *myBullet;
	point *invaderBullet;
    int myBulletStepDelay = 125;
	int enemyBulletStepDelay = 200;
    long myBulletStep;
	long invaderBulletStep;
    int invaderStepDelay;
    long invaderStep;
    int invaderXDirection;
    int invaderYDirection;
    int invaderBounced;
	void setupLevel(int lvl);
    void spawnInvader(int x, int y);
    void moveInvaders();
    void stepInvader(point *position);
    void detectCollisions();
	void detectShipCollision(point *position);
	void detectEnemyShot(point *position);
	void detectBulletsCollision();
    void gameOver();
    void draw();  
    void drawShip();
    void drawBullets();
    void fire();
	void invaderShoot();
    void resetGame();
  public:

   // PUBLIC DATA MEMBERS
    void update();
    void play();
    void levelUp();
};

//////////////////////////////////////////////////////// END OF THE CLASS DEFINITION ////////////////////////////////////////////////////////

