#include "Game.h"
#include<iostream>

using namespace std;

Game :: Game(WINDOW *game) :esnake(game), fruit(game), score(0), gameSpeed(2) {
    this->game = game;
}

int Game :: menu() {

    //1-jogar
    //2-scores
    //3-mudar caracteristicas do elementos do jogo
    mvprintw(13, 50, "Choose game Mode: ");
    mvprintw(14, 50, "[1] Cheetah");
    mvprintw(15, 50, "[2] Snake");
    mvprintw(16, 50, "[3] Snail");
    refresh();
    cin >> gameSpeed;
    if (gameSpeed < 1 || gameSpeed > 3)
        gameSpeed = 150;
    gameSpeed*=75;
    
    return 1;
}

void Game :: jogar() {

    //1-se clicar numa tecla ainda a definir ele ierá comecar o jogo, mas terá de colocar o nome antes
    //2-se clicar no 0, irá sair do jogo antes de sequer começar
}

void Game :: play() {

    int lastKey = 0;
    keypad(game, TRUE);
    menu();
    mvwaddstr(stdscr, 4, 100, "SCORE:");
    wrefresh(stdscr);
    wborder(game, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(game);
    curs_set(FALSE);

    int i = 0;
    fruit.addFood();

    while (i == 0) {
        mvprintw(4, 108, "%d", score);   
        refresh();
        esnake.print(gameSpeed);
        int key = wgetch(game);
        if (key == -1 || (lastKey == KEY_RIGHT && key == KEY_LEFT) || (lastKey == KEY_LEFT && key == KEY_RIGHT) || (lastKey == KEY_DOWN && key == KEY_UP) || (lastKey == KEY_UP && key == KEY_DOWN) || (key != KEY_RIGHT && key!= KEY_LEFT && key != KEY_DOWN && key != KEY_UP && key != 27)) {

            key = lastKey;
        }
        lastKey = key;
        if (key == 27) {
            exit(1);
        }
        esnake.move(key);
        if (esnake.findApple(fruit.getPosition())) {

            wrefresh(game);
            do {
                fruit.addFood();
            } while (esnake.overlapApple(fruit.getPosition()));

            score++;

        }
    }

}

void Game :: scores() {

    for (size_t i = 0; i < players.size(); i++) {
    }
}

void Game :: extras() {}