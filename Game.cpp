#include "Game.h"

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
