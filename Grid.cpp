#include "grid.h"

Grid::Grid():rows(3),cols(3){ 
        for(int i=0;i<rows;i++){
                for (int j=0;j<cols;j++){
                        grid[i][j] = ' ';           
                }
        }
        printGrid();
}

void Grid::drawRow(int row){
        std::cout << grid[row][0] << '|' << grid[row][1] << '|' << grid[row][2] <<std::endl;
}

void Grid::drawDivider(){
        std::cout << '_' << ' ' << '_' << ' ' << '_' << std::endl;
}

void Grid::printGrid(){
        drawRow(0);
        drawDivider();
        drawRow(1);
        drawDivider();
        drawRow(2);
}