#pragma once
#include <iostream>
#include <cmath>
#include <string>

enum ChessPiece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum PieceColor { WHITE, BLACK, NONE };

class Piece{
public:
  Piece();
  void setSpace(Piece*);
  void setEmpty();
  void setPieceAndColor(ChessPiece, PieceColor);
  ChessPiece getPiece();
  PieceColor getColor();
  void setX(int ex) { x = ex; }
  void setY(int why) { y = why; }
  int getX() { return x; }
  int getY() { return y; }
protected:
  ChessPiece piece;
  PieceColor color;
  int x, y;
};

class Board {
public:
  bool makeMove(int x1, int y1, int x2, int y2);
  void printBoard();
  bool doMove();
  void setBoard();
  bool playGame();
  Piece *getSquare(int x, int y) { return &board[x][y]; }
  void setSquare(Piece *s, int x, int y) { board[x][y] = *s; }

protected:
  Piece board[8][8];
  PieceColor turn=WHITE;
};

class Pawn : public Piece{
  public:
    bool movePiece(Piece* thisPawn, Piece* thatSpace);
  private:
    
};

class King : public Piece{
  public:
    bool movePiece(Piece* thisKing, Piece* thatSpace);
  private:
};

class Knight : public Piece{
  public:
    bool movePiece(Piece* thisKnight, Piece* thatSpace);
  private:
};

class Bishop : public Piece{
  public:
    Bishop(Board& board) : gameBoard(board) {}
    bool movePiece(Piece* thisBishop, Piece* thatSpace);
  private:
    Board& gameBoard;
};

class Queen : public Piece{
  public:
    Queen(Board& board) : gameBoard(board) {}
    bool movePiece(Piece* thisQueen, Piece* thatSpace);
  private:
    Board& gameBoard;
};

class Rook : public Piece{
  public:
    Rook(Board& board) : gameBoard(board) {}
    bool movePiece(Piece* thisRook, Piece* thatSpace);
  private:
    Board& gameBoard;
};
