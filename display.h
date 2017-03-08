//////////////////////////////////////////////////// CLASS DEFINITION OF DISPLAY CLASS - //////////////////////////////////////////////////////

class Display
{
  private:
    LedControl lc = LedControl(DIN, CLK, CS, 1);
  public:
    Display();                                              // CONSTRUCTOR OF DISPLAY CLASS
    void drawObject(int size, point position);
    void draw(Ball *ball);
    void draw(Controller *controller);
    void clear(int duration);
    void clear();
    void newGame();
    void update();
    void flashSprite(byte *sprite, int frames, int duration);
    void drawSprite(byte *sprite);
    void drawRow(int y, byte row);
    void drawPixel(int x, int y);
    void drawPixel(int x, int y, bool on);
    void chaos(int duration);
};


/////////////////////////////////////////////////////////// END OF CLASS DEFINITION ///////////////////////////////////////////////////////////
