#pragma once
#include "Apple.h"
#include "Snake.h"
#include<iostream>
#include<string>
#include<vector>
#include "coordenates.h"

using namespace std;

class Game
{
    string name;
    int score;
    Snake esnake;
    Apple fruit;
    WINDOW* game;
    int gameSpeed;
public:
    vector <int> players;
    Game(WINDOW*);
    int menu();
    void jogar();
    void play();
    void scores();
    void extras();
};

