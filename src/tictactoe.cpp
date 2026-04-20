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


bool ComputerTurn(int mode, char player_check) {
    if (mode == 2 && player_check == 'O') {
        return true;
    }
    if (mode == 3 && player_check == 'X') {
        return true;
    }
    return false;
}
//


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

int FirstSpot (const vector <char>& board) {
    for (int i = 1; i <= 9; i++) {
        if ((board[i] != 'X') && (board[i] != 'O')) {
            return i;
        }
    }
    return -1;
}



string TicTacToe(int mode) {
    bool winner = false;
    char player_check = 'X';
    int player_input;
    int counter = 0;
    cout << "Welcome to Tic Tac Toe!" << endl;
    vector <char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printBoard(board);


    while (counter < 9) {
        bool computer_turn = ComputerTurn(mode, player_check);
        if (computer_turn) {
            player_input = FirstSpot(board);
            cout << endl<<"Computer chooses:" << endl;
        }
        else {
            cout << endl << "What is your move?" << endl;
            while (true) {
                cin >> player_input;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, Please try again:" << endl;
                   continue;
                }
                if (((player_input < 1) || (player_input > 9) ||(board[player_input] == 'X') || (board[player_input] == 'O'))){
                    cout << "Invalid input, Please try again:" << endl;
                    continue;
                }
                    break;
            }
        }


            board[player_input] = player_check;
            counter++;
        printBoard(board);

            if (check_winner(board, player_check)) {
                string win(1,player_check);
                string winner = "Player " + win + " wins!";
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
                cout <<"It's a tie!" << endl;
                return "It's a tie!";
            }


        }
return "It's a tie!";
}