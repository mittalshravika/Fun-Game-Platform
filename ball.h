
/////////////////////////////////////////////////// THE CLASS DEFINITION OF BALL ///////////////////////////////////////////////////////////////

class Ball
{

  private:    
    int previousDirection;
    bool between(int val, int min, int max);
    bool isHitPaddle(Controller *controller);    
    int getNewDirection();
  public:
    point position;
    point direction;
    void move(Controller *controller);
    void initialise();
};

/////////////////////////////////////////////////// END OF THE CLASS DEFINITION ///////////////////////////////////////////////////////////////

