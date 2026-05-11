#include <iostream>
using namespace  std;
#include "src/tictactoe.hpp"
#include <vector>
#include <string>
#include <limits>

int main() {

     bool again = true;
     string input = "y";
     while (again) {
          cout <<"What mode do you want to play?" << endl;
          cout << "Type '1' for Human v.s. Human" << endl;
          cout << "Type '2' for Human (Goes 1st) v.s. Computer (Goes 2nd)" << endl;
          cout << "Type '3' for Computer (Goes 1st) v.s. Human (Goes 2nd)" << endl;
          cout <<"Select mode: ";
          int mode;
          while (true) {
               cin >> mode;
               if (cin.fail() || mode <1 || mode > 3) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout  << "Please enter a valid mode: ";
               }
               else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
               }
          }

          int mode_trap = 0;
          if (input == "1") {
               cout << "Would you like to include a trap cell in your game?";
               cout << "1. Yes (enter '1')";
               cout << "2. No (enter '2')";
          } // for portfolio 3, thus far got code getting a valid input for the new trap cell mode.
          //still need to add backend stuff into a new TicTacToe(mode, mode_trap) that will have to randomly add trap cell
          // and include case if/when users hit a trap cell.
          while (true) {
               cin >> mode_trap;
               if (cin.fail() || mode_trap <1 || mode_trap > 2) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout  << "Please enter a valid mode: ";
               }
               else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
               }
          }

          TicTacToe(mode, mode_trap);
          cout << "Type 'y' or 'n' to play again." << endl;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          getline(cin, input);
          while ((input != "n") && (input != "y")) {
               cout << "Please enter a valid input." << endl;
               getline(cin, input);
          }
          if (input == "n") {
               again = false;
          }
     }
     cout << "Thanks for playing!" << endl;
}