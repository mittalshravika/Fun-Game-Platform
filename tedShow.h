///////////////////////////////////////////////////// DEFINITION OF THE CLASS TED-SHOW //////////////////////////////////////////////////////
class TedShow
{
  private:

    // PRIVATE DATA MEMBERS
    tedShowState state;
    int stepDelay;
    byte evenRow;
    byte oddRow;
    bool toggle;
    int gameSpeedDelay;
    point stick;
    long elapsed;
    void startTimer(); 
    void draw();  
    void drawCatcher();
    void drawLights();
    void drawStick();
    void updateLights();
    void updateStick();
    void newGame();
  public:
 
   // PUBLIC DATA MEMBERS 
    void update();
    void play();
    void gameOver();
    void levelUp();
};


//////////////////////////////////////////////////////////////////// END ///////////////////////////////////////////////////////////////////
