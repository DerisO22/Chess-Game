#include <iostream>
#include <string>
#include "chessBoard.h"

using namespace std;

int main()
{
  Board gameBoard;
  string s;
  bool newgame = true;
  cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;
  cout << "Here Are Some Important Details To Play The Game:" << endl
       << "1. To make a move, enter the cordinates of the piece you want to move and and space that you want it to go." << endl
       << "2. You will be prompted if you want to play against an ai chess bot" << endl
       << "3. Other than this, the rules are exactly of that as chess. Have Fun!" << endl; 
  cout << "Enter any key to continue: ";
  cin >> s;

  while(newgame){
    cout << "Inside Loop" << endl;
    gameBoard.setBoard();
    cout << "Board Set" << endl;
    while (gameBoard.playGame());
    cout << "Do you want to play again? (y for yes, anything else for no) ";
    cin >> s;
    if (s != "y")
      newgame = false;
  }


  return 0;
}