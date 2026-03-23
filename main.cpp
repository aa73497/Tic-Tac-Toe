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
          TicTacToe();
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