#ifndef HW1_LIB_H
#define HW1_LIB_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

enum class cells
{
    NONCELL,
    EMPTY,
    PEG,
};

void start_game(int gameType, int boardType);

void print_move(int board_number, int row_index, int column_index, char direction);
void print_board(vector<vector<cells>> board, int row, int column, string upper_word);
void print_result(int row_ind, int col_ind, vector<vector<cells>> board);

void make_move(char side, int board_number, int row_ind, int col_ind, char direction, vector<vector<cells>> &board);
void find_random_move(vector<char> possibleDirections, int row, int column, int &row_ind, int &col_ind, char &direction, char &side);
void find_column_index(int board_number,char column_letter, int &column_index);

bool check_input(vector<char> possibleDirections, int board_number, int input_type, string user_input);
bool check_if_finished(int board_number, int row, int column, vector<vector<cells>> board);
bool check_legal_move(char side, int board_number, int row_ind, int column_ind, char direction, vector<vector<cells>> board);

void get_board_info(int board_type, vector<vector<cells>> &board, int &boardRow, int &boardColumn, string &upperString, vector<char> &possibleDirections);

#endif /* HW_LIB_H */