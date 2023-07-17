#include <iostream>
#include <chrono>

int main() {
    //std::cout << "Hello World!" << std::endl;
    //random number generator
    double seed = 1000;
    srand(seed);
    //random number between 6 and 10;
    int board_dimension = 5 + rand() % 10 + 1;

    //generate board
    char** board = new char*[board_dimension];
    for (int i = 0; i < board_dimension; i++) {
        board[i] = new char[board_dimension];
    }
    for (int i = 0; i < board_dimension; i++) {
        for (int j = 0; j < board_dimension; j++) {
            board[i][j] = 'O';
        }
    }

    //create a start and endpoint
    //int point_on_board = 

    std::cout << board_dimension << std::endl;
    for (int i = 0; i < board_dimension; i++) {
        for (int j = 0; j < board_dimension; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    //clear memory
    for (int i = 0; i < board_dimension; i++) {
        delete[] board[i];
        board[i] = nullptr;
    }
    delete[] board;

    return 0;
}