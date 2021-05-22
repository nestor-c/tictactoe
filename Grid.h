#ifndef GRID_H
#define GRID_H
#include <iostream>

class Grid{
    const int rows;
    const int cols;
    char grid[3][3];
    private:    
        void drawRow(int);
        void drawDivider();
    public:
        Grid();
        void printGrid();
        void setGrid(int,char);
        char checkGrid(int, int);
};
#endif
