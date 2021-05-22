#include "Game.h"
#include "time.h"


Game::Game():player1('X'),player2('O'){
        srand(time(NULL));
        currPlayer = rand()%2 + 1;

        startPlay();
        mainLoop();
}

void Game::startPlay(){
        char currToken;
        currPlayer == 1 ? currToken = 'X': currToken = 'O';
        std::cout << "Welcome to tic-tac-toe! Match three of the same tokens horizontally, vertically, or diagonally and win!" << std::endl;
        std::cout << "Player " << currPlayer << "(" << currToken <<") goes first!" << std::endl;
        grid.printGrid();
}

void Game::fillChoice(int choice){
        grid.setGrid(choice, currPlayer);
}

//Only works with a standard 3x3 grid
bool Game::checkHorizontal(){

        int row=lastChoice.first;
        int col=lastChoice.second;

        if (col == 0){
                if (grid.checkGrid(row,col+1) == grid.checkGrid(row,col) && grid.checkGrid(row,col+1) == grid.checkGrid(row,col+2)){
                        return true;
                } 
        }
        else if (col == 1){
                if (grid.checkGrid(row,col-1) == grid.checkGrid(row,col) && grid.checkGrid(row,col-1) == grid.checkGrid(row,col+1)){
                        return true;
                }
        }
        else if (col == 2 ){
                if (grid.checkGrid(row,col-2) == grid.checkGrid(row,col) && grid.checkGrid(row,col-2) == grid.checkGrid(row,col-1)){
                        return true;
                }
        }

        return false;
}

bool Game::checkVertical(){
        int row=lastChoice.first;
        int col=lastChoice.second;

        if (row == 0){
                if (grid.checkGrid(row+1,col) == grid.checkGrid(row,col) && grid.checkGrid(row+1,col) == grid.checkGrid(row,row+2)){
                        return true;
                } 
        }
        else if (row == 1){
                if (grid.checkGrid(row-1,col) == grid.checkGrid(row,col) && grid.checkGrid(row+1,col) == grid.checkGrid(row-1,col)){
                        return true;
                }
        }
        else if (row == 2 ){
                if (grid.checkGrid(row-2,col) == grid.checkGrid(row,col) && grid.checkGrid(row-1,col) == grid.checkGrid(row-2,col)){
                        return true;
                }
        }

        return false;
}

bool Game::checkDiagonal(){
        int row=lastChoice.first;
        int col=lastChoice.second;

        if (row == 0 && col == 0){
                if (grid.checkGrid(row+1,col+1) == grid.checkGrid(row,col) && grid.checkGrid(row+1,col+1) == grid.checkGrid(row+2,row+2)){
                        return true;
                } 
        }
        else if (row == 1 && col == 1){
                if (grid.checkGrid(row-1,col-1) == grid.checkGrid(row,col) && grid.checkGrid(row+1,col+1) == grid.checkGrid(row-1,col-1)){
                        return true;
                }
        }
        else if (row == 2 && col == 2){
                if (grid.checkGrid(row-2,col-2) == grid.checkGrid(row,col) && grid.checkGrid(row-1,col-1) == grid.checkGrid(row-2,col-2)){
                        return true;
                }
        }

        return false;
}

void Game::showOptions(){
        int options = 1;
        for (int i = 0; i < grid.numRows();i++){
                for (int j = 0; j<grid.numCols();j++){
                        if (grid.checkGrid(i,j) == ' ') std::cout << options << " ";
                        options++;
                }
        }
        std::cout << std::endl;
}