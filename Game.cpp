#include "Game.h"
#include "time.h"

Game::Game():player1('X'),player2('O'){
        win = false;
        lastChoice.first = -1;
        lastChoice.second = -1;
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

void Game::fillChoice(int row,int col){
        char token;
        currPlayer == 1 ? token = 'X': token = 'O';
        grid.setGrid(row,col, token);
}

//Only works with a standard 3x3 grid
bool Game::checkHorizontal(){
        int row=lastChoice.first;
        int col=lastChoice.second;

        if (col == 0){
                if (grid.checkGrid(row,col+1) == grid.checkGrid(row,col) && grid.checkGrid(row,col+1) == grid.checkGrid(row,col+2)){
                        std::cout << "Player" << currPlayer << " you win horizontally!" << std::endl;
                        return true;
                } 
        }
        else if (col == 1){
                if (grid.checkGrid(row,col-1) == grid.checkGrid(row,col) && grid.checkGrid(row,col-1) == grid.checkGrid(row,col+1)){
                        std::cout << "Player" << currPlayer << " you win horizontally!" << std::endl;
                        return true;
                }
        }
        else if (col == 2 ){
                if (grid.checkGrid(row,col-2) == grid.checkGrid(row,col) && grid.checkGrid(row,col-2) == grid.checkGrid(row,col-1)){
                        std::cout << "Player" << currPlayer << " you win horizontally!" << std::endl;
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
                        std::cout << "Player" << currPlayer << " you win vertically!" << std::endl;
                        return true;
                } 
        }
        else if (row == 1){
                if (grid.checkGrid(row-1,col) == grid.checkGrid(row,col) && grid.checkGrid(row+1,col) == grid.checkGrid(row-1,col)){
                        std::cout << "Player" << currPlayer << " you win vertically!" << std::endl;
                        return true;
                }
        }
        else if (row == 2 ){
                if (grid.checkGrid(row-2,col) == grid.checkGrid(row,col) && grid.checkGrid(row-1,col) == grid.checkGrid(row-2,col)){
                        std::cout << "Player" << currPlayer << " you win vertically!" << std::endl;
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
                        std::cout << "Player" << currPlayer << " you win diagonally!" << std::endl;
                        return true;
                } 
        }
        else if (row == 1 && col == 1){
                if (grid.checkGrid(row-1,col-1) == grid.checkGrid(row,col) && grid.checkGrid(row+1,col+1) == grid.checkGrid(row-1,col-1)){
                        std::cout << "Player" << currPlayer << " you win diagonally!" << std::endl;
                        return true;
                }
        }
        else if (row == 2 && col == 2){
                if (grid.checkGrid(row-2,col-2) == grid.checkGrid(row,col) && grid.checkGrid(row-1,col-1) == grid.checkGrid(row-2,col-2)){
                        std::cout << "Player" << currPlayer << " you win diagonally!" << std::endl;
                        return true;
                }
        }
        else if (row == 2 && col == 0){
                if (grid.checkGrid(row-1,col+1) == grid.checkGrid(row,col) && grid.checkGrid(row-1,col+1) == grid.checkGrid(row-2,col+2)){
                        std::cout << "Player" << currPlayer << " you win diagonally!" << std::endl;
                        return true;
                }
        }
        else if (row == 0 && col == 2){
                if (grid.checkGrid(row+2,col-2) == grid.checkGrid(row,col) && grid.checkGrid(row+2,col-2) == grid.checkGrid(row+1,col-1)){
                        std::cout << "Player" << currPlayer << " you win diagonally!" << std::endl;
                        return true;
                }
        }

        return false;
}

void Game::showOptions(){
        int options = 1;
        std::cout << "These are the current options available:" << std::endl;
        for (int i = 0; i < grid.numRows();i++){
                for (int j = 0; j<grid.numCols();j++){
                        if (grid.checkGrid(i,j) == ' ') std::cout << options << " ";
                        options++;
                }
        }
        std::cout<<std::endl;
}

void Game::mainLoop(){
        int choice;
        char currToken;
        while(!win){   
                currPlayer == 1 ? currToken = 'X': currToken = 'O';     
                std::cout << "Player" << currPlayer << "(" << currToken << ")" << " it's your turn!"<< std::endl; 
                showOptions();
                std::cout<< "Make a choice from those available: " ;
                std::cin >> choice;
                std::cout << std::endl;
                convertChoice(choice);
                fillChoice(lastChoice.first,lastChoice.second);
                checkWin();
                grid.printGrid();
                currPlayer == 1 ? currPlayer = 2: currPlayer = 1;
        }
}

void Game::checkWin(){
        if (checkDiagonal() || checkHorizontal() || checkVertical()){
                win =true;
        }   
}

void Game::convertChoice(int choice){
        switch(choice){
                case 1: 
                       lastChoice.first = 0;
                       lastChoice.second = 0;
                       break;          
                       
                case 2: 
                       lastChoice.first = 0;
                       lastChoice.second = 1;
                       break;          
                       
                case 3: 
                       lastChoice.first = 0;
                       lastChoice.second = 2;
                       break;          
                       
                case 4: 
                       lastChoice.first = 1;
                       lastChoice.second = 0;
                       break;          
                       
                case 5: 
                       lastChoice.first = 1;
                       lastChoice.second = 1;
                       break;          
                       
                case 6: 
                       lastChoice.first = 1;
                       lastChoice.second = 2;
                       break;          
                       
                case 7: 
                       lastChoice.first = 2;
                       lastChoice.second = 0;
                       break;          
                case 8: 
                       lastChoice.first = 2;
                       lastChoice.second = 1;
                       break;          
                case 9: 
                       lastChoice.first = 2;
                       lastChoice.second = 2;
                       break;                      
        }
}