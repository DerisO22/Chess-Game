/*
Author:                   Deris C. O’Malley
Class:                    CSI-240-03
Assignment:               Final Project
Date Assigned:            9, March
Due Date:                 23, April, 11:59PM

Description:
The console-based chess game utilizes many programming concepts including: inheritance,
Polymorphism, OOP, vectors, pointers, dynamically allocated memory, and exception 
Handling. Just like chess all the rules are exactly the same and two users are able
To play against each other. The moves are stored within a text file and when the game
Ends, the user will be able to play another game.

Certification of Authenticity:
I certify that this is entirely my own work,except where I have given fully-documented 
References to the work of others. I understand the definition and consequences of 
Plagiarism and acknowledge that the assessor of this assignment may, for the purpose 
of assessing this assignment: 
-Reproduce this assignment and provide a copy to another member of academic staff; 
and/or 
- Communicate a copy of this assignment to a plagiarism checking service (which
May then retain a copy of this assignment on its database for the purpose of future
Plagiarism checking)
*/
#include "chessBoard.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Board gameBoard;
  string s;
  bool newgame = true;
  ofstream moveFile;
  moveFile.open("moves.txt");
  moveFile << "";
  moveFile.close();
  //Introduction
  cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ "
          "____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  "
          "|  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  "
          "\\_____|_|  |_|______|_____/_____/ \n" << endl;
  cout << "Here Are Some Important Details To Play The Game:" << endl
       << "1. To make a move, enter the cordinates of the piece you want to "
         "move and and space that you want it to go." << endl
       << "2. You will be prompted if you want to play against an ai chess bot" << endl
       << "3. Other than this, the rules are exactly of that as chess. Have Fun!" << endl;
  cout << "Enter any key to continue: ";
  cin >> s;

  //Game Loop
  while (newgame) {
    gameBoard.setBoard();
    while (gameBoard.playGame()) {
    }
    gameBoard.outputGameMoves();
    cout << "Do you want to play again? (y for yes, anything else for no) ";
    cin >> s;
    gameBoard.setTurn(PieceColor::WHITE); 
    
    if (s != "y")
      newgame = false;
  }
  return 0;
}