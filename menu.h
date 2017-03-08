//////////////////////////////////////////////////// DEFINITION OF THE MENU CLASS - ///////////////////////////////////////////////////////////

class Menu
{
  // PRIVATE CLASS MEMBERS

  private:
    const int width = 32;
    const int height = 8;
    games selectedGame;
    long elpased;
    games currentGame = gmMenu;
    void updateMenu();
    void updatePong();

   // PUBLIC CLASS MEMBERS
  public:
    void initialize();
    void update();
    bool between(int val, int min, int max);
    void startGame(int offset);
};


///////////////////////////////////////////////////////// END OF THE EDFINITION //////////////////////////////////////////////////////////////
