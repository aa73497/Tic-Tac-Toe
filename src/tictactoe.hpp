#include <string>
#include <vector>
using namespace std;
string TicTacToe(int mode, int mode_trap);
bool ComputerTurn(int mode, char player_check);
bool check_winner(const vector<char>&board, char player_check);
int FirstSpot(const vector<char>& board);
int RandomTrap();
bool isTrapHit(int input, int cell, int mode);
int MaxCells(int mode);
bool isDraw(int counter, int mode);