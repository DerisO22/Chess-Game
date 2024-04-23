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
 
bool Bishop::movePiece(Piece* thatSpace) {
  //get x and y values of 
  int bishopX = this->getX();
  int bishopY = this->getY();
  int thatX = thatSpace->getX();
  int thatY = thatSpace->getY();
  bool invalid = false;

  //Detect Same Color
  if(thatSpace->getColor() == this->getColor()){
    return false;
  }

  //get direction of move
  if (abs(bishopX - thatX) == abs(bishopY - thatY)){
    int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
    int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

    //Check for diagnol obstruction
    for (int i = 1; i < abs(bishopX - thatX); i++){  
      if (gameBoard->getSquare(bishopX + xIncrement*i, bishopY + yIncrement*i)->getColor() != PieceColor::NONE){
        return false;
      }
    }
  } else {
    return false;
  }

  if (!invalid){
    return true;
  } else {
    return false;
  }
}