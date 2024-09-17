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

bool Pawn::movePiece(Piece *thatSpace) {
  //Get x and y values of objects
  int pawnX = this->getX();
  int pawnY = this->getY();
  int thatX = thatSpace->getX();
  int thatY = thatSpace->getY();

  //Detect same color
  if(thatSpace->getColor() == this->getColor()){
    return false;
  }

  int forwardDirection = (this->getColor() == PieceColor::WHITE) ? -1 : 1;  // White pawns move up (decrease in x), black pawns move down (increase in x)

  // Normal forward move
  if (pawnY == thatY && thatSpace->getColor() == PieceColor::NONE) {
      // Double move
      if(((this->getColor() == PieceColor::WHITE && pawnX == 6) || (this->getColor() == PieceColor::BLACK && pawnX == 1)) && (pawnX + 2*forwardDirection == thatX) && thatSpace->getColor() == PieceColor::NONE) {
          std::cout << "Double Forward Move" << std::endl;
          return true;
      }
      // Single move
      else if (pawnX + forwardDirection == thatX) {
          std::cout << "Single Forward Move" << std::endl;
          return true;
      }
  }

  // Capturing move
  if ((this->getColor() == PieceColor::WHITE || this->getColor() == PieceColor::BLACK) &&
      abs(thatY - pawnY) == 1 &&
      pawnX + forwardDirection == thatX &&
      thatSpace->getColor() != PieceColor::NONE && 
      thatSpace->getColor() != this->getColor()) {
      std::cout << "Capturing Move" << std::endl;
      return true;
  }

  std::cout << "Invalid Move" << std::endl;
  return false;
}