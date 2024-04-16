#include "chessBoard.h"
 
Piece::Piece() 
{
  piece = EMPTY;
  color = NONE;
}

void Piece::setSpace(Piece* space)
{
  color = space->getColor();
  piece = space->getPiece();
}

void Piece::setEmpty()
{
  color = NONE;
  piece = EMPTY;
}

ChessPiece Piece::getPiece()
{
  return piece;
}

PieceColor Piece::getColor()
{
  return color;
}

void Piece::setPieceAndColor(ChessPiece p, PieceColor c)
{
  piece = p;
  color = c;
}

void Board::printBoard() {
  using namespace std;
  cout << "  y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
  for (int i = 0; i < 8; i++)
  {
    cout << " " << i << "  ";
    for (int j = 0; j < 8; j++)
    {
      ChessPiece p = board[i][j].getPiece();
      PieceColor c = board[i][j].getColor();

      switch (p)
      {
      case KING: (c == WHITE) ? cout << " ♔ " : cout << " ♚ ";
        break;
      case QUEEN: (c == WHITE) ? cout << " ♕ " : cout << " ♛ ";
        break;
      case BISHOP:(c == WHITE) ? cout << " ♗ " : cout << " ♝ ";
        break;
      case KNIGHT:(c == WHITE) ? cout << " ♘ " : cout << " ♞ ";
        break;
      case ROOK: (c == WHITE) ? cout << " ♖ " : cout << " ♜ ";
        break;
      case PAWN: (c == WHITE) ? cout << " ♙ " : cout << " ♟ ";
        break;
      case EMPTY: cout << "  " << " ";
        break;
      default: cout << "XXX";
        break;
      }

    }
    cout << endl;
  } 

} 

bool Board::doMove() {
  using namespace std;
  cout << "Within Do Move" << endl;
  string move;
  int x1, x2, y1, y2;
  bool stop = false; 
  while (!stop)
  {
    (turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
    cout << "Enter Move: ";
    cin >> move;
    x1 = move[0] - 48;
    y1 = move[1] - 48;
    x2 = move[2] - 48;
    y2 = move[3] - 48;
    if (getSquare(x1, y1)->getColor() == turn)
    {
      if (makeMove(x1, y1, x2, y2) == false)
      {
        cout << "Invalid move, try again." << endl;
      }
      else
      {
        stop = true;
      }
    }
    else
    {
      cout << "That's not your piece. Try again." << endl;
    }
  }
  if (getSquare(x2, y2)->getPiece() == KING)
  {
    if (getSquare(x1, y1)->getColor() == WHITE)
    {
      cout << "WHITE WINS" << endl;
      return false;
    }
    else
    {
      cout << "BLACK WINS" << endl;
      return false;
    }
  }

  if (turn == BLACK)
    turn = WHITE;
  else
    turn = BLACK;

  return true;

}

void Board::setBoard()
{  
  std::cout << "Within Set Board" << std::endl;
  //Place Pieces
  board[7][0].setPieceAndColor(ROOK, WHITE);
  board[7][1].setPieceAndColor(KNIGHT, WHITE);
  board[7][2].setPieceAndColor(BISHOP, WHITE);
  board[7][3].setPieceAndColor(QUEEN, WHITE);
  board[7][4].setPieceAndColor(KING, WHITE);
  board[7][5].setPieceAndColor(BISHOP, WHITE);
  board[7][6].setPieceAndColor(KNIGHT, WHITE);
  board[7][7].setPieceAndColor(ROOK, WHITE);

  board[0][0].setPieceAndColor(ROOK, BLACK);
  board[0][1].setPieceAndColor(KNIGHT, BLACK);
  board[0][2].setPieceAndColor(BISHOP, BLACK);
  board[0][3].setPieceAndColor(QUEEN, BLACK);
  board[0][4].setPieceAndColor(KING, BLACK);
  board[0][5].setPieceAndColor(BISHOP, BLACK);
  board[0][6].setPieceAndColor(KNIGHT, BLACK);
  board[0][7].setPieceAndColor(ROOK, BLACK);

  //Place Pawns
  for (int i = 0; i < 8; i++)
  {
    board[6][i].setPieceAndColor(PAWN, WHITE);
    board[1][i].setPieceAndColor(PAWN, BLACK);
  }
  //Set Empty Spaces
  for (int i = 2; i < 6; i++)
  {
    for (int j = 0; j < 8; j++)
      board[i][j].setPieceAndColor(EMPTY, NONE);
  }

  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
      board[i][j].setX(i);
      board[i][j].setY(j);
    }
}

bool Board::playGame()
{
  std::cout << "Within Play Game" << std::endl;
  printBoard();
  return doMove();
}

bool Board::makeMove(int x1, int y1, int x2, int y2) {
  //std::cout << "Within Make Move" << std::endl;
  //Checking for turns will be done previous to this
  King* king = nullptr;
  Queen* queen = nullptr;
  Pawn* pawn = nullptr;
  Knight* knight = nullptr;
  Bishop* bishop = nullptr;
  Rook* rook = nullptr;
  
  using namespace std;
  if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8)
  {
    std::cout << "One of your inputs was out of bounds" << std::endl;
    return false;
  }
  Piece* src = getSquare(x1, y1);
  Piece* dest = getSquare(x2, y2);

  if (src->getColor() == dest->getColor() && dest->getColor() != NONE)
  {
    std::cout << "Invalid move: cannot land on your own piece" << std::endl;
    return false;
  }

  switch (src->getPiece()) 
  { 
  case KING: 
    return king->movePiece(src, dest);
    break; 
  case QUEEN: 
    //cout << src.getPiece() << endl;
    return queen->movePiece(src, dest);
    break;
  case BISHOP: 
    //cout << src.getPiece() << endl;
    return bishop->movePiece(src, dest);
    break;
  case KNIGHT: 
    //cout << src.getPiece() << endl;
    return knight->movePiece(src, dest);
    break;
  case ROOK: 
    //cout << src.getPiece() << endl;
    return rook->movePiece(src, dest);
    break;
  case PAWN: 
    //cout << src.getPiece() << endl;
    return pawn->movePiece(src, dest);
    //cout << "Pawn Moved" << endl;
    break;
  case EMPTY: std::cout << "You do not have a piece there" << std::endl;  return false;
    break;
  default: std::cerr << "Something went wrong in the switch statement in makeMove()" << std::endl;
    break;
  }
  return false;
}