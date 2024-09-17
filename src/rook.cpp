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

bool Rook::movePiece(Piece *thatSpace) {
  //Get x and y values
  int rookX = this->getX();
  int rookY = this->getY();
  int thatX = thatSpace->getX();
  int thatY = thatSpace->getY();
  bool valid = true;

  //Detect same color
  if(thatSpace->getColor() == this->getColor()){
    return false;
  }

  // Ensure the Rook moves in a straight line either horizontally or vertically
  if (rookX != thatX && rookY != thatY) {
    std::cout << "Invalid Move: Rooks can only move straight horizontally or vertically." << std::endl;
    return false;
  }

  //Same Piece Detect
  if(this -> getColor() == thatSpace -> getColor()){
    return false;
  }

  int xIncrement = 0;
  int yIncrement = 0;

  // Determine the direction of movement
  if (rookX == thatX) {
    if (thatY > rookY) {
      yIncrement = 1;
    } else {
      yIncrement = -1;
    }
  } else if (rookY == thatY) {
    if (thatX > rookX) {
      xIncrement = 1;
    } else {
      xIncrement = -1;
    }
  }

  // Begin checking for obstructions from the next square to the destination
  int currentX = rookX + xIncrement;
  int currentY = rookY + yIncrement;

  // Iterate through the path to ensure no pieces are obstructing the path
  while ((currentX != thatX || currentY != thatY) && valid) {
    if (gameBoard->getSquare(currentX, currentY)->getPiece() != ChessPiece::EMPTY) {
      valid = false; //Obstruction
      break;
    }
    currentX += xIncrement;
    currentY += yIncrement;
  }
  return valid;
}