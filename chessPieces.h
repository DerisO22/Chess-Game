#pragma once

enum Color {
    WHITE,
    BLACK
};

class Piece{
public:
    void movePiece();

private:

};

class King : public Piece{
public:
    bool checkLegalMove(){};

private:
    Color color;
};

class Queen : public Piece{
public:
    bool checkLegalMove(){}

private:
    Color color;
};

class Bishop : public Piece{
public:
    bool checkLegalMove(){}

private:
    Color color;
};

class Rook : public Piece{
public:
    bool checkLegalMove(){}

private:
    Color color;
};

class Knight : public Piece{
public:
    bool checkLegalMove(){}

private:
    Color color;
};

class Pawn : public Piece{
public:
    bool checkLegalMove(){}

private:
    Color color;
};
