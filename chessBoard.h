#pragma once

#include <vector>
#include <string>

using namespace std;

class ChessBoard{
public:
    ChessBoard(){};
    void outputBoard();

private:
//Store en-pessant states, turns, writes
    char board[8][8];
};

