////////////////////////////////////////////////////////////////////THE DEFINITION OF THE FUNCTIONS OF CONTOLLER ARE AS FOLLOWS ////////////////////////////////////////////////////


Controller::Controller()
{
  // INITIALISING ALL THE VARIABLES
  size = 3;
  position.x = 1;
  position.y = 7;
  pinMode(ControllerRightButtonPin, INPUT_PULLUP);
  pinMode(ControllerLeftButtonPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}


void Controller::update()
{
  // THE POSITION OF THE CONTOLLER(PADDLER) IS BEING UPDATED BY THIS FUNCTION
  position.x = map(analogRead(ControllerPotPin), 0, 1020, 8 - size, 0);
  rightButtonPressed = !digitalRead(ControllerRightButtonPin);
  leftButtonPressed = !digitalRead(ControllerLeftButtonPin);
  rightButtonWasPressed = (previousRightButtonPressed == true && rightButtonPressed == false);
  leftButtonWasPressed = (previousLeftButtonPressed == true && leftButtonPressed == false);

  digitalWrite(13, rightButtonPressed);
  
  previousRightButtonPressed = rightButtonPressed;
  previousLeftButtonPressed = leftButtonPressed;
}


///////////////////////////////////////////////////////////////////////// CONTROLLER DEFINITION ENDS /////////////////////////////////////////////////////////////////////////////////
