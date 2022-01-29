#ifndef HW1_LIB_H
#define HW1_LIB_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

enum class cells
{
    NONCELL,
    EMPTY,
    PEG,
};

void start_game(int gameType, int boardType, bool is_load, const string &load_inp);
/* game implementation */

void load_game(const string &file_name, vector<vector<cells>> &board, int &boardRow, int &boardColumn, string &upperString, vector<char> &possibleDirections, int &number_of_moves);
void save_game(const string &file_name, vector<vector<cells>> board, int boardRow, int boardColumn, int number_of_moves, string human_or_comp);
/* save and load functions */

void print_move(int board_number, int row_index, int column_index, char direction);
void print_board(vector<vector<cells>> board, int row, int column, string upper_word = "");
void print_result(int row_ind, int col_ind, vector<vector<cells>> board);
/* print functions */

void string_parse(string user_input, vector<string> &words);
void make_move(char side, int board_number, int row_ind, int col_ind, char direction, vector<vector<cells>> &board);
void find_random_move(vector<char> possibleDirections, int row, int column, int &row_ind, int &col_ind, char &direction, char &side);
void find_column_index(int board_number, char column_letter, int &column_index);
/* make move will make the move */
/* find column index will find the column index by looking letter */


int check_load_save(string user_input);
bool check_input(vector<char> possibleDirections, int board_number, int input_type, string user_input = "");
bool check_if_finished(int board_number, int row, int column, vector<vector<cells>> board);
bool check_legal_move(char side, int board_number, int row_ind, int column_ind, char direction, vector<vector<cells>> board);
/* some check functions */

void get_board_info(int board_type, vector<vector<cells>> &board, int &boardRow, int &boardColumn, string &upperString, vector<char> &possibleDirections);

#endif /* HW_LIB_H */