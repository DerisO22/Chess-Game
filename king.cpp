#include "chessBoard.h"
 
bool King::movePiece(Piece* thisKing, Piece* thatSpace) {
  //off board inputs should be handled elsewhere (before this)
  //squares with same color should be handled elsewhere (before this)
  if (abs(thatSpace->getX() - thisKing->getX()) == 1)
    if (abs(thatSpace->getY() - thisKing->getY()) == 1)
    {
      thatSpace->setSpace(thisKing);
      thisKing->setEmpty();
      return true;
    }
    else
    {
      return false;
    }
  else
  {
    return false;
  }
}