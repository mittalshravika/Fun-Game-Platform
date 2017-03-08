/////////////////////////////////////////////////// THE CLASS DEFINITION OF CONTROLLER IS - ////////////////////////////////////////////////////

class Controller
{
  private:
    bool previousRightButtonPressed;
	bool previousLeftButtonPressed;   // BOOLEAN-TYPE VARIABLES
  public:
    point position;
    bool rightButtonPressed;
	bool leftButtonPressed;
    int size;
    Controller();
    void update();
    bool rightButtonWasPressed;
	bool leftButtonWasPressed;
};


///////////////////////////////////////////////////////// END OF CLASS DEFINITION /////////////////////////////////////////////////////////////
