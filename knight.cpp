#include "chessBoard.h"

bool Knight::movePiece(Piece* thisKnight, Piece* thatSpace)
{
  //off board inputs should be handled elsewhere (before this)
  //squares with same color should be handled elsewhere (before this)
  int knightX = thisKnight->getX();
  int knightY = thisKnight->getY();
  int thatX = thatSpace->getX();
  int thatY = thatSpace->getY();

  if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
  {
    thatSpace->setSpace(thisKnight);
    thisKnight->setEmpty();
    return true;
  }
  else
  {
    return false;
  }
}