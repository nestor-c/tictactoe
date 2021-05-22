#include "Grid.h"

Grid::Grid():rows(3),cols(3){ 
        //Initialize grid with ' ' in each space
        for(int i=0;i<rows;i++){
                for (int j=0;j<cols;j++){
                        grid[i][j] = ' ';           
                }
        }
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

void Grid::setGrid(int choice, char player){
        switch(choice){
                case 1: 
                        grid[0][0]=player;break;                
                case 2: 
                        grid[0][1]=player;break;                
                case 3: 
                        grid[0][2]=player;break;                
                case 4: 
                        grid[1][0]=player;break;                
                case 5: 
                        grid[1][1]=player;break;                
                case 6: 
                        grid[1][2]=player;break;                
                case 7: 
                        grid[2][0]=player;break;                
                case 8: 
                        grid[2][1]=player;break;                
                case 9: 
                        grid[2][2]=player;break;                
        }
}

char Grid::checkGrid(int row, int col){
        return grid[row][col];
}

int Grid::gridSize(){
      return sizeof(grid)/sizeof(grid[0]);
}

int Grid::numRows(){
        return rows;
}

int Grid::numCols(){
        return cols;
}

     