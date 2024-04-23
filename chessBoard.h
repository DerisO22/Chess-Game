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
#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

enum class ChessPiece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum class PieceColor { WHITE, BLACK, NONE };

class Piece {
public:
  Piece();
  virtual ~Piece(){};
  virtual bool movePiece(Piece *thatSpace);
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

class GameMove{
private:
  Piece* movedPiece;
  std::string moveDetails;

public:
  GameMove(Piece* piece, std::string& details) : movedPiece(piece), moveDetails(details){}
  ~GameMove(){};
  Piece* getMovedPiece(){ return movedPiece; }
  string getMoveDetails(){ return moveDetails; }
};

class Board {
public:
  Board(){};
  ~Board();
  bool makeMove(int x1, int y1, int x2, int y2);
  bool doMove();
  void outputGameMoves();
  void printBoard();
  void setBoard();
  void setTurn(PieceColor color);
  void initializePiece(ChessPiece piece, PieceColor color, int x, int y);
  bool playGame();
  Piece *getSquare(int x, int y) { return board[x][y]; }
  Piece* createPiece(ChessPiece pieceType, PieceColor color);
  void setSquare(Piece *piece, int x, int y);

protected:
  Piece *board[8][8];
  PieceColor turn = PieceColor::WHITE;
  static int moveNum;
  vector<GameMove*> gameMoves;
};

//Derived Piece Classes for Move Validation
class Pawn : public Piece {
public:
  Pawn(){};
  ~Pawn(){};
  //Pawn(Board *board) : gameBoard(board) {}
  bool movePiece(Piece *thatSpace) override;

private:
  //Board* gameBoard;
};

class King : public Piece {
public:
  King(){};
  ~King(){};
  //King(Board *board) : gameBoard(board) {}
  bool movePiece(Piece *thatSpace) override;
  bool getInCheckStatus() { return isInCheck; }

private:
  bool isInCheck;
  //Board* gameBoard;
};

class Knight : public Piece {
public:
  Knight(){};
  ~Knight(){};
  //Knight(Board *board) : gameBoard(board) {}
  bool movePiece(Piece *thatSpace) override;

private:
  //Board* gameBoard;
};

class Bishop : public Piece {
public:
  Bishop(){};
  ~Bishop(){};
  Bishop(Board *board) : gameBoard(board) {}
  bool movePiece(Piece *thatSpace) override;

private:
  Board *gameBoard;
};

class Queen : public Piece {
public:
  Queen(){};
  ~Queen(){};
  Queen(Board *board) : gameBoard(board) {}
  bool movePiece(Piece *thatSpace) override;

private:
  Board *gameBoard;
};

class Rook : public Piece {
public:
  Rook(){};
  ~Rook(){};
  Rook(Board *board) : gameBoard(board) {}
  bool movePiece(Piece *thatSpace) override;

private:
  Board *gameBoard;
};
