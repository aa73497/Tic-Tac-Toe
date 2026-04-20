#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/tictactoe.hpp"
using namespace std;
#include <sstream>
#include <iostream>
#include <string>

TEST_CASE("ComputerTurn works for mode 2") {
    REQUIRE(ComputerTurn(2, 'O') == true);
    REQUIRE(ComputerTurn(2, 'X') == false);
}

TEST_CASE("ComputerTurn works for mode 3") {
    REQUIRE(ComputerTurn(3, 'X') == true);
    REQUIRE(ComputerTurn(3, 'O') == false);
}

TEST_CASE("check_winner detects a win") {
    vector<char> board = {'0', 'X', 'X', 'X', '4', '5', '6', '7', '8', '9'};
    REQUIRE(check_winner(board, 'X') == true);
}

TEST_CASE("check_winner finds no winner") {
    vector<char> board = {'0', 'X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'X'};
    REQUIRE(check_winner(board, 'X') == false);
}

TEST_CASE("FirstSpot finds the lowest spot") {
    vector<char> board = {'0', 'X', 'O', '3', '4', '5', '6', '7', '8', '9'};
    REQUIRE(FirstSpot(board) == 3);
}