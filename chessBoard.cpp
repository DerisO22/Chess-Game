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

int Board::moveNum = 0;

Board::~Board(){
  //Board Deallocation
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(board[i][j] != nullptr){
        delete board[i][j];
        board[i][j] = nullptr;
      }
    }
  }
}

void Board::outputGameMoves(){
  int i = 0;
  //Output Vector based on the piece moved
  for(auto *item : gameMoves){
    i++;
    switch(item->getMovedPiece()->getPiece()){
      case ChessPiece::KING: 
        cout << i << ". " << "King Move: " << item->getMoveDetails() << endl;
        break;
      case ChessPiece::KNIGHT: 
        cout << i << ". " << "Knight Move: " << item->getMoveDetails() << endl;
        break;
      case ChessPiece::QUEEN: 
        cout << i << ". " << "Queen Move: " << item->getMoveDetails() << endl;
        break;
      case ChessPiece::ROOK: 
        cout << i << ". " << "Rook Move: " << item->getMoveDetails() << endl;
        break;
      case ChessPiece::BISHOP: 
        cout << i << ". " << "Bishop Move: " << item->getMoveDetails() << endl;
        break;
      case ChessPiece::PAWN: 
        cout << i << ". " << "Pawn Move: " << item->getMoveDetails() << endl;
        break;
      default:
        break;
    }
  }
  //Since end of game, also deallocate and clear vector
  for(int i=0; i<gameMoves.size(); i++){
    delete gameMoves[i];
    gameMoves[i] = nullptr;
  }
  gameMoves.clear();
}

void Board::setTurn(PieceColor color) { turn = color; }

void Board::setSquare(Piece* piece, int x, int y) {
  //Dynamically update board square
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if(board[x][y] != nullptr) {
            delete board[x][y];
        }
        board[x][y] = piece;
    } else {
        cout << "Trying to set a piece out of bounds" << endl;
    }
}

Piece* Board::createPiece(ChessPiece pieceType, PieceColor color) {
    Piece* piece = nullptr;
    //Creates a new piece type and sets attributes
    switch (pieceType) {
        case ChessPiece::PAWN: piece = new Pawn(); break;
        case ChessPiece::ROOK: piece = new Rook(); break;
        case ChessPiece::KNIGHT: piece = new Knight(); break;
        case ChessPiece::BISHOP: piece = new Bishop(); break;
        case ChessPiece::QUEEN: piece = new Queen(); break;
        case ChessPiece::KING: piece = new King(); break;
        default: piece = new Piece(); // Empty
    }
    piece->setPieceAndColor(pieceType, color);
    return piece;
}

void Board::printBoard() {
  using namespace std;
  cout << endl << "Move" << ": " << moveNum << "\n\n";
  cout << "  y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
  for (int i = 0; i < 8; i++) {
    cout << " " << i << "  ";
    for (int j = 0; j < 8; j++) {
      ChessPiece p = board[i][j]->getPiece();
      PieceColor c = board[i][j]->getColor();
      //Output piece based on Piece type and color
      switch (p) {
      case ChessPiece::KING:
        (c == PieceColor::WHITE) ? cout << " ♔ " : cout << " ♚ ";
        break;
      case ChessPiece::QUEEN:
        (c == PieceColor::WHITE) ? cout << " ♕ " : cout << " ♛ ";
        break;
      case ChessPiece::BISHOP:
        (c == PieceColor::WHITE) ? cout << " ♗ " : cout << " ♝ ";
        break;
      case ChessPiece::KNIGHT:
        (c == PieceColor::WHITE) ? cout << " ♘ " : cout << " ♞ ";
        break;
      case ChessPiece::ROOK:
        (c == PieceColor::WHITE) ? cout << " ♖ " : cout << " ♜ ";
        break;
      case ChessPiece::PAWN:
        (c == PieceColor::WHITE) ? cout << " ♙ " : cout << " ♙ ";
        break;
      case ChessPiece::EMPTY:
        cout << "  "
             << " ";
        break;
      default:
        cout << "XXX";
        break;
      }
    }
    cout << endl;
  }
}

bool Board::doMove() {
  //Extra Move Validation, move info, switching turns
  string move;
  int x1, x2, y1, y2;
  bool stop = false;
  // Get move loop
  while (!stop) {
    (turn == PieceColor::WHITE) ? cout << "White's turn" << endl
                                : cout << "Black's turn" << endl;
    cout << "Enter Move: ";
    cin >> move;
    //Correct Input Format validation
    if (move.length() != 4 || !isdigit(move[0]) || !isdigit(move[1]) ||
        !isdigit(move[2]) || !isdigit(move[3])) {
      cout << "Please enter your move in the correct format (e.g., \"5233\")." << endl;
    }

    x1 = move[0] - '0';
    y1 = move[1] - '0';
    x2 = move[2] - '0';
    y2 = move[3] - '0';
    //Out of bounds
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
      cout << "Invalid move: coordinates out of bounds. Try again." << endl;
      continue;
    }
    if (getSquare(x1, y1)->getColor() == turn &&
        getSquare(x1, y1)->getPiece() != ChessPiece::EMPTY) {
      if (!makeMove(x1, y1, x2, y2)) {
        cout << "Invalid move, try again." << endl;
      } else {
        stop = true;
      }
    } else {
      cout << "That's not your piece or the square is empty. Try again." << endl;
    }
  }
  // Vector to store game moves(will output to file)
  moveNum++;
  GameMove* newMove = new GameMove {board[x2][y2], move};
  gameMoves.push_back(newMove);

  //outputs to file each move in case game crashes(Highly Possible)
  ofstream moveHistory("moves.txt", ios::app);
  stringstream moveInfo;
    moveInfo << moveNum << " " << ((turn == PieceColor::WHITE) ? "White" : "Black") << ": " << move << endl;
  moveHistory << moveInfo.str();
  moveHistory.close();

  // Switch Turns
  if (turn == PieceColor::BLACK)
    turn = PieceColor::WHITE;
  else
    turn = PieceColor::BLACK;

  return true;
}

void Board::initializePiece(ChessPiece piece, PieceColor color, int x, int y) {
  //Piece Initialization at start of game at a certain board index
  switch (piece) {
  case ChessPiece::KING:
    board[x][y] = new King();
    break;
  case ChessPiece::PAWN:
    board[x][y] = new Pawn();
    break;
  case ChessPiece::QUEEN:
    board[x][y] = new Queen(this);
    break;
  case ChessPiece::BISHOP:
    board[x][y] = new Bishop(this);
    break;
  case ChessPiece::ROOK:
    board[x][y] = new Rook(this);
    break;
  case ChessPiece::KNIGHT:
    board[x][y] = new Knight();
    break;
  case ChessPiece::EMPTY:
    board[x][y] = new Piece();
    break;
  default:
    break;
  }
  //Set Piece Attributes
  board[x][y]->setPieceAndColor(piece, color);
  board[x][y]->setX(x);
  board[x][y]->setY(y);
}

void Board::setBoard() {
  // Initialize Chess Pieces and Empty Squares
  // White Pieces
  initializePiece(ChessPiece::ROOK, PieceColor::WHITE, 7, 0);
  initializePiece(ChessPiece::KNIGHT, PieceColor::WHITE, 7, 1);
  initializePiece(ChessPiece::BISHOP, PieceColor::WHITE, 7, 2);
  initializePiece(ChessPiece::QUEEN, PieceColor::WHITE, 7, 3);
  initializePiece(ChessPiece::KING, PieceColor::WHITE, 7, 4);
  initializePiece(ChessPiece::BISHOP, PieceColor::WHITE, 7, 5);
  initializePiece(ChessPiece::KNIGHT, PieceColor::WHITE, 7, 6);
  initializePiece(ChessPiece::ROOK, PieceColor::WHITE, 7, 7);
  // White Pawns
  for (int i = 0; i < 8; i++) {
    initializePiece(ChessPiece::PAWN, PieceColor::WHITE, 6, i);
  }

  // Black Pieces
  initializePiece(ChessPiece::ROOK, PieceColor::BLACK, 0, 0);
  initializePiece(ChessPiece::KNIGHT, PieceColor::BLACK, 0, 1);
  initializePiece(ChessPiece::BISHOP, PieceColor::BLACK, 0, 2);
  initializePiece(ChessPiece::QUEEN, PieceColor::BLACK, 0, 3);
  initializePiece(ChessPiece::KING, PieceColor::BLACK, 0, 4);
  initializePiece(ChessPiece::BISHOP, PieceColor::BLACK, 0, 5);
  initializePiece(ChessPiece::KNIGHT, PieceColor::BLACK, 0, 6);
  initializePiece(ChessPiece::ROOK, PieceColor::BLACK, 0, 7);
  // Black Pawns
  for (int i = 0; i < 8; i++) {
    initializePiece(ChessPiece::PAWN, PieceColor::BLACK, 1, i);
  }
  // Set Empty Spaces
  for (int i = 2; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      initializePiece(ChessPiece::EMPTY, PieceColor::NONE, i, j);
    }
  }
}

bool Board::playGame() {
  // Game Loop
  printBoard();
  return doMove();
}

bool Board::makeMove(int x1, int y1, int x2, int y2) {
    // Extra out of bounds check
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        std::cout << "One of your inputs was out of bounds" << std::endl;
        return false;
    }
    //Pointers to the piece at certain coordinate
    Piece *src = getSquare(x1, y1);
    Piece *dest = getSquare(x2, y2);
    
    if (src != nullptr && src->movePiece(dest)) {
    // Create a new piece of the same type at the destination square
        // new ...() is handled in createPiece
        Piece* newPiece = createPiece(src->getPiece(), src->getColor());
        newPiece->setX(x2);
        newPiece->setY(y2);
        setSquare(newPiece, x2, y2); 
        // Set source square to empty
        setSquare(new Piece(), x1, y1);
        return true;
    } else {
        cout << "Invalid move" << endl;
        return false;
    }
}