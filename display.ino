//////////////////////////////////////////////////////////////////// THE DEFINITION OF THE FUNCTIONS OF THE CLASS DISPLAY //////////////////////////////////////////////////////////

Display::Display()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 0);
  lc.clearDisplay(0);
}


void Display::newGame() {
  
  // SETUP OF THE NEW GAME TAKES PLACE AS - 
  
  lc.clearDisplay(0);

  chaos(1500);
  lc.clearDisplay(0);
}

void Display::drawSprite(byte *sprite) {
  
  // SPRITE HELPS IN DRAWING SHAPES ON A LED MATRIX
  
  for (int r = 0; r < 8; r++) {
    lc.setRow(0, r, sprite[r]);
  }
}

void Display::drawRow(int y, byte row)
  
  // LIGHTS ON A ROW 

{
  lc.setRow(0, y, row);
}

void Display::update()
{
}

void Display::clear(int duration)
{
  // CLEARS THE SCREEN AND DIPLAYS THE BLANK SCREEN FOR A DURATION
 
  lc.clearDisplay(0);

  delay(duration);
}

void Display::clear()
{
  // JUST CLEARS THE SCREEN
  
  lc.clearDisplay(0);
}


void Display::draw(Ball *ball)
{
  // DRAWS THE BALL ON THE LED MATRIX ON THE SPECIFIED POSITION 
  
  drawObject(1, ball->position);
}

void Display::draw(Controller *controller)
{
  // DRAWS THE PADDLER(CONTROLLER) ON THE LED MATRIX AT ITS PARTICULAR POSITION
  
  drawObject(controller->size, controller->position);
}

void Display::drawPixel(int x, int y)
{
  // DISPLAYS A PIXEL ON THE LED MATRIX
  
  drawPixel(x, y, true);
}

void Display::drawPixel(int x, int y, bool on)
{
  lc.setLed(0, y, x, on);
}

void Display::drawObject(int size, point position)
{
  // DISPLAYS AN OBJECT ON THE LED MATRIX
  
  for (int i = 0; i < size; i++)
  {
    lc.setLed(0, position.y, position.x + i, true);
  }
}

void Display::flashSprite(byte *sprite, int frames, int duration)
{ 
  for (int i = 0 ; i < frames; i++)
  {
    drawSprite(sprite);

    delay(duration);

    clear(duration);
  }
}

void Display::chaos(int duration)
{
  clear();
  
  long start = millis();
  
  while(millis() - start < duration)
  {
    int x = random(0,8);
    int y = random(0, 8);
    
    lc.setLed(0, y, x, true);   
    
    delay(10);
  }
  
  for(int i = 0; i<8; i++)
  {
    lc.setRow(0, i, 255);
  }
  
  delay(1000);
}


//////////////////////////////////////////////////////////////////////////////  END OF THE DEFINITION //////////////////////////////////////////////////////////////////////////////
