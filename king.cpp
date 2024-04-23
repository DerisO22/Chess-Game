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

bool King::movePiece(Piece *thatSpace) {
  //Detect Same Color
  if(thatSpace->getColor() == this->getColor()){
    return false;
  }
  
  if (abs(thatSpace->getX() - this->getX()) <= 1 && abs(thatSpace->getY() - this->getY()) <= 1) {
    // Additional code to ensure move doesn't place King into check would go here
    return true;
  } else {
    return false;
  }
}