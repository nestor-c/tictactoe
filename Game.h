#ifndef GAME_H
#define GAME_H
#include "Grid.h"
#include <utility>

class Game{
    private:
        bool win = false;
        Grid grid;
        std::pair<int,int> lastChoice;
        int currPlayer;
        char player1;
        char player2;
        bool checkHorizontal();
        bool checkVertical();
        bool checkDiagonal();
        void checkWin();

    public:
        Game();
        void fillChoice(int);
        void startPlay();
        void mainLoop();
        void showOptions();        
};
#endif
