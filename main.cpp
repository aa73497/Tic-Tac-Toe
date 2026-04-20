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
          TicTacToe(mode);
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