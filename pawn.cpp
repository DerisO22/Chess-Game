#include "chessBoard.h"
  
bool Pawn::movePiece(Piece* thisPawn, Piece* thatSpace) {
  std::cout << "Function Called";
  //off board inputs should be handled elsewhere (before this)
  //squares with same color should be handled elsewhere (before this)
  using namespace std;
  //bool invalid = false;
  int pawnX = thisPawn->getX();
  int pawnY = thisPawn->getY();
  int thatX = thatSpace->getX();
  int thatY = thatSpace->getY();
  
  //White Pawn
  if (thisPawn->getColor() == WHITE)
  {
    if (pawnX == thatX+1 && thatY == pawnY && thatSpace->getColor() == NONE)
    {
      thatSpace->setSpace(thisPawn);
      thisPawn->setEmpty();
      return true;
    }
    else if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX  && thatSpace->getColor() == BLACK)
      {
        thatSpace->setSpace(thisPawn);
        thisPawn->setEmpty();
        return true;
      }
      else
      {
        return false;
      }
  }

  //Black Pawn
  else if (thisPawn->getColor() == BLACK)
    {
      if (pawnX == thatX - 1 && thatY == pawnY && thatSpace->getColor() == NONE)
      {
        thatSpace->setSpace(thisPawn);
        thisPawn->setEmpty();
        return true;
      }
      else if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY  && thatSpace->getColor() == WHITE)
        {
          thatSpace->setSpace(thisPawn);
          thisPawn->setEmpty();
          return true;
        }
        else
        {
          return false;
        }
    }
    else
    {
      cout << "Invalid Move!!" << endl;
      return false;
    }
}