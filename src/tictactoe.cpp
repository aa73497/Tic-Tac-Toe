#include <iostream>
#include <string>
#include <vector>
using namespace std;
void TicTacToe() {
    bool winner = false;
    char player_check = 'X';
    cout << "Welcome to Tic Tac Toe!" << endl;
    vector <char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //I was having trouble getting it print 3x3, so made first index =0 to fix
    for (int i = 1; i <= 9; i++) {
        cout << " | "; //prints out layout and separates positions
        cout << board[i];
        cout << " | ";
        if ((i%3)==0) {
            cout << endl; //checks if no remainder so its 3 rows per column
        }
    }
    // ---------------------------------------------------------------------------- creates game board
    //actual game element

    while (winner == false) { //prior to reiteration, checks if no winner yet
        int temp;
        cout << " What is your move? "; cout << endl;
        cin >> temp;
        if ((temp > 9 || temp < 1) || board[temp] == 'X' || board[temp] == 'O') { //checks for invalid moves
            cout << "That is not a valid move! Try again. " << endl;
        }
        else {
            for (int i = 1; i <= 9; i+2) {
                if ((i = 1) && board[1] == player_check) {
                    if (board[5] == player_check) {
                        if (board[9] == player_check) {
                            winner = true;
                        }
                    }
                    if ((board[4] == player_check) && (board[7] == player_check)) {
                        winner = true;
                    }
                    else if ((board[2] == player_check) && (board[3] == player_check)) {
                        winner = true;
                    }
                }

                if ((i = 3) && board[3] == player_check) {
                    if (board[5] == player_check) {
                        if (board[7] == player_check) {
                            winner = true;
                        }
                    }
                }

                if ((i = 5) && board[5] == player_check) {
if ((board[2] == player_check) && (board[8] == player_check)) {
    winner = true;
}
                    else if ((board[4] == player_check) && (board[6] == player_check)) {
                        winner = true;
                    }
                }

                if (i = 9 && board[9] == player_check) {
                    if ((board[8] == player_check) && board[7] == player_check) {
                        winner = true;
                    }
                    else if ((board[3] == player_check) && (board[6] == player_check)) {
                        winner = true;
                    }
                }
            }
            if (player_check == 'X') {
                player_check = '0';
            }
            else{
                player_check = 'X';
            }
        }
        for (int i = 1; i <= 9; i++) {
            cout << " | "; //prints out layout and separates positions
            cout << board[i];
            cout << " | ";
            if ((i%3)==0) {
                cout << endl; //checks if no remainder so its 3 rows per column
            }
        }
    }
} // Program  works fine if an error occurs; however, having issues displaying valid inputs
//wanted to check for diagonal wins at 1 and 3 and then either a horizonatal/vertical win at 1, 5, and 9 since that covers all possible wins but can't get output when allowed input is given