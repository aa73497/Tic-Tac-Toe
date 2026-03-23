#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <limits>
void printBoard(const vector <char>& board){
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
    cout << "-----+-----+-----" << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6]<< endl;
    cout << "-----+-----+-----" << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9]<< endl;
    // ---------------------------------------------------------------------------- creates game board
    //actual game element
}

bool check_winner(const vector <char>& board, const char player_check) {
    if ((board[1] == player_check) && (board[5] == player_check) && (board[9] == player_check)){
        return true;
    }// diagonal winners
    if ((board[3] == player_check) && (board[5] == player_check) && (board[7] == player_check)) {
        return true;
    }
    for (int i = 1; i <= 9; i+=3) { //horizontal win
        if ((board[i] == player_check) && (board[i+1] == player_check) && (board[i+2] == player_check)) {
            return true;
        }
    }
    for (int i = 1; i <= 3; i++) {
        if ((board[i] == player_check) && (board[i+3] == player_check) && (board[i+6] == player_check)) {
            return true;
        }
    }
    return false;
}

string TicTacToe() {
    bool winner = false;
    char player_check = 'X';
    int player_input;
    int counter = 0;
    cout << "Welcome to Tic Tac Toe!" << endl;
    vector <char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //I was having trouble getting it print 3x3, so made first index =0 to fix


    while (counter != 10) {
        printBoard(board);
        cout << endl << "What is your move?" << endl;
        while (true) {
            cin >> player_input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, Please try again:" << endl;
                cin >> player_input;
            }
             if (((player_input < 1) || (player_input > 9) ||(board[player_input] == 'X') || (board[player_input] == 'O'))){
                printBoard(board);
                cout << "Invalid input, Please try again:" << endl;
                 continue;
            }
            else {
                break;
            }
        }
            board[player_input] = player_check;
            counter++;
            if (check_winner(board, player_check)) {
                string win(1,player_check);
                string winner = "Player " + win + " wins!";
                printBoard(board);
                cout << winner << endl;
                return winner;
            }
            if (player_check == 'X') {
                player_check = 'O';
            }
            else {
                player_check = 'X';
            }
            if (counter == 9) {
                return "It's a tie!";
            }


        }

}