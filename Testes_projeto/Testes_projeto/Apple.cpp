#include "Apple.h"
#include<iostream>

using namespace std;

Apple :: Apple(WINDOW *game) : pos({5,5}){
    this->game = game;
}

void Apple :: addFood() {

    int maxX = getmaxx(game);
    int maxY = getmaxy(game);

    srand(time(NULL));
    pos.y = rand() % (maxX - 100) + 3;
    pos.x = rand() % (maxY - 120) + 3;

    start_color();
    init_pair(2, COLOR_RED, COLOR_BLACK);
    fruit = COLOR_PAIR(2) | '@';

    mvwaddch(game, pos.y, pos.x, fruit);
    wrefresh(game);
}

coordenates Apple :: getPosition() {

    return pos;

}