#include "Snake.h"
#include "coordenates.h"
#include<iostream>
#include<curses.h>
#include<string>
#include<list>
#include<vector>

using namespace std;

Snake :: Snake(WINDOW* game) :coords({ 10,10 }), type('S'){

    this->game = game;
    size = 1;
    elements.push_front(coords);

}

void Snake::print(int gameSpeed) {
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    wattron(game, COLOR_PAIR(1));
    mvwaddch(game, elements.front().y, elements.front().x, type);
    wrefresh(game);
    wtimeout(game, gameSpeed);
    wattroff(game, COLOR_PAIR(1));
}

void Snake :: move(int key) {
    int counter = 0;
    switch (key) {
    case KEY_RIGHT:
        coords = elements.front();
        coords.x++;
        elements.push_front(coords);

        eraseTail();
        if (elements.front().x > 108) {
            //gameover();
            exit(1);
        }
        break;
    case KEY_LEFT:
        coords = elements.front();
        coords.x--;
        elements.push_front(coords);
        eraseTail();
        if (elements.front().x < 1) {
            //gameover();
            exit(1);
        }
        break;
    case KEY_UP:
        coords = elements.front();
        coords.y--;
        elements.push_front(coords);
        eraseTail();
        if (elements.front().y < 1) {
            //gameover();
            exit(1);
        }
        break;
    case KEY_DOWN:
        coords = elements.front();
        coords.y++;
        elements.push_front(coords);
        eraseTail();
        if (elements.front().y > 18) {
            //gameover();
            exit(1);
        }
        break;
    default:
        break;
    }
    for (list<coordenates> ::iterator it = elements.begin(); it != elements.end(); it++) {
        if (elements.front().x == (*it).x && elements.front().y == (*it).y)
            counter++;

        if (counter >= 2)
            exit(1);
    }
}

void Snake::eraseTail() {
    if (size < elements.size()) {
        wrefresh(game);

        mvwaddch(game, elements.back().y, elements.back().x, ' ');
        elements.pop_back();

    }
    else {
        mvwaddch(game, elements.back().y, elements.back().x, ' ');
    }
}

coordenates Snake :: GetHeadPosition() {

    return elements.front();
}

bool Snake :: findApple(const coordenates& fruit) {

    if (fruit.x == elements.front().x && fruit.y == elements.front().y) {
        size++;
        return true;
    }
    else
        return false;
}
bool Snake :: overlapApple(const coordenates& fruit) {
    if (fruit.x == elements.front().x && fruit.y == elements.front().y) {
        return true;
    }
    else
        return false;
}
