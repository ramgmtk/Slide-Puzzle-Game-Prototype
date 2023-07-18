#include <iostream>
#include <chrono>

int main() {
    //std::cout << "Hello World!" << std::endl;
    //random number generator
    double seed = 1000;
    srand(seed);
    //random number between 6 and 10;
    int board_dimension_x = 5 + rand() % 10 + 1;
    int board_dimension_y = board_dimension_x;
    //table for removing duplicate array elements.
    int* rng_table = new int[board_dimension_x * board_dimension_y];
    int rng_table_adjusted_size = board_dimension_x * board_dimension_y;

    //generate board
    char** board = new char*[board_dimension_x];
    for (int i = 0; i < board_dimension_x; i++) {
        board[i] = new char[board_dimension_y];
    }
    for (int i = 0; i < board_dimension_x; i++) {
        for (int j = 0; j < board_dimension_y; j++) {
            board[i][j] = 'O';
            rng_table[i * board_dimension_y + j] = i * board_dimension_y + j;
        }
    }

    //create a start and endpoint
    int rng_point_index = rand() % board_dimension_y + (board_dimension_x * board_dimension_y - board_dimension_y); 
    int end_point = rng_table[rng_point_index];
    rng_table[rng_point_index] = rng_table[rng_table_adjusted_size-1];
    rng_table_adjusted_size -= 1;

    rng_point_index = rand() % board_dimension_y;
    int start_point = rng_table[rng_point_index];
    rng_table[rng_point_index] = rng_table[rng_table_adjusted_size-1];
    rng_table_adjusted_size -= 1;

    int x_index = end_point / board_dimension_y;
    int y_index = end_point % board_dimension_y;
    board[x_index][y_index] = 'X';

    x_index = start_point / board_dimension_y;
    y_index = start_point % board_dimension_y;
    board[x_index][y_index] = 'X';


    //test print
    std::cout << board_dimension_x << std::endl;
    for (int i = 0; i < board_dimension_x; i++) {
        for (int j = 0; j < board_dimension_y; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < board_dimension_x; i++) {
        for (int j = 0; j < board_dimension_y; j++) {
            std::cout << rng_table[i * board_dimension_y + j] << ' ';
        }
        std::cout << std::endl;
    }


    //clear memory
    for (int i = 0; i < board_dimension_x; i++) {
        delete[] board[i];
        board[i] = nullptr;
    }
    delete[] board;
    delete[] rng_table;

    return 0;
}