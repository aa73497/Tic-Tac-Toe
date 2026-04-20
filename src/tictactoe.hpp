#include <string>
#include <vector>
using namespace std;
string TicTacToe(int mode);
bool ComputerTurn(int mode, char player_check);
bool check_winner(const vector<char>&board, char player_check);
int FirstSpot(const vector<char>& board);