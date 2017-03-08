//////////////////////////////////////////////// DEFINITION OF THE CLASS SNAKE ///////////////////////////////////////////////////////////////

class Snake
{
private:
    
    // PRIVATE DATA MEMBERS
	LinkedList<point*> segments;
	point* spawnSegment(int x, int y);
	void setApple();
	point direction;
	point apple;
	bool addSegment;
	steering steer;
	long snakeStepElapsed;
	long snakeStepDelay;
	void gameOver();
	void draw();
	void detectCollisions();
public:
	
     // PUBLIC DATA MEMBERS
	void update();
	void play();
	void move();
};



////////////////////////////////////////////////////////// END OF THE DEFINITION //////////////////////////////////////////////////////////////S
