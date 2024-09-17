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

bool Queen::movePiece(Piece *thatSpace) {
  //Get x and y values of objects 
  int queenX = this->getX();
  int queenY = this->getY();
  int thatX = thatSpace->getX();
  int thatY = thatSpace->getY();
  int yIncrement = 0;
  int xIncrement = 0;
  bool valid = true;

  //Detect same color
  if(thatSpace->getColor() == this->getColor()){
    return false;
  }

  //X and Y increment For Vertical and Horizontal movement
  //Direction
  if(queenX == thatX || queenY == thatY){
    if(queenX == thatX){
      xIncrement = 0;
    } else if (thatX - queenX > 0){
      xIncrement = 1;
    } else {
      xIncrement = -1;
    }

    if(queenY == thatY){
      yIncrement = 0;
    } else if (thatY - queenY > 0){
      yIncrement = 1;
    } else {
      yIncrement = -1;
    }
  }

  //Check for obstruction on the vertical and horizontals
  int x = queenX + xIncrement, y = queenY + yIncrement;
    while (x != thatX || y != thatY) {
        if (gameBoard->getSquare(x, y)->getPiece() != ChessPiece::EMPTY ||
            gameBoard->getSquare(x, y)->getColor() == this->getColor()) {
            valid = false; 
            break;
        }
        x += xIncrement;
        y += yIncrement;
    }
  // Diagonal Movement like a Bishop (Left, Right, Up, Down)
  if(abs(queenX - thatX) == abs(queenY - thatY)) {
    if (thatX - queenX > 0) {
      xIncrement = 1;
    } else {
      xIncrement = -1;
    }
    if (thatY - queenY > 0) {
      yIncrement = 1;
    } else {
      yIncrement = -1;
    }
    
    valid = true;
    //Check For Obstruction On Diagnols
    for(int i = 1; i < abs(queenX - thatX); i++) {
      if(gameBoard->getSquare(queenX + i*xIncrement, queenY + i*yIncrement)->getPiece() != ChessPiece::EMPTY ||
         gameBoard->getSquare(queenX + i*xIncrement, queenY + i*yIncrement)->getColor() == this->getColor()) {
        valid = false;
        break;
      }
    }
  }
  return valid;
}