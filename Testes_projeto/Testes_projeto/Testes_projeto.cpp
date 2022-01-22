#include<curses.h>
#include<iostream>
#include <list>
#include "Game.h"
#include "Snake.h"
#include "Apple.h"
#include "coordenates.h"

using namespace std;

WINDOW* game; 

void gamepause() {
    cout << "                                                                                                                                                                                  " << endl;
    cout << "        GGGGGGGGGGGGG                                                                   PPPPPPPPPPPPPPPPP                                                                         " << endl;
    cout << "     GGG::::::::::::G                                                                   P::::::::::::::::P                                                                        " << endl;
    cout << "   GG:::::::::::::::G                                                                   P::::::PPPPPP:::::P                                                                       " << endl;
    cout << "  G:::::GGGGGGGG::::G                                                                   PP:::::P     P:::::P                                                                      " << endl;
    cout << " G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee           P::::P     P:::::Paaaaaaaaaaaaa  uuuuuu    uuuuuu      ssssssssss       eeeeeeeeeeee    " << endl;
    cout << "G:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee         P::::P     P:::::Pa::::::::::::a u::::u    u::::u    ss::::::::::s    ee::::::::::::ee  " << endl;
    cout << "G:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee       P::::PPPPPP:::::P aaaaaaaaa:::::au::::u    u::::u  ss:::::::::::::s  e::::::eeeee:::::e" << endl;
    cout << "G:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e       P:::::::::::::PP           a::::au::::u    u::::u  s::::::ssss:::::se::::::e     e:::::e" << endl;
    cout << "G:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e       P::::PPPPPPPPP      aaaaaaa:::::au::::u    u::::u   s:::::s  ssssss e:::::::eeeee::::::e" << endl;
    cout << "G:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e        P::::P            aa::::::::::::au::::u    u::::u     s::::::s      e:::::::::::::::::e " << endl;
    cout << "G:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee         P::::P           a::::aaaa::::::au::::u    u::::u        s::::::s   e::::::eeeeeeeeeee  " << endl;
    cout << " G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e                  P::::P          a::::a    a:::::au:::::uuuu:::::u  ssssss   s:::::s e:::::::e           " << endl;
    cout << "  G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e               PP::::::PP        a::::a    a:::::au:::::::::::::::uus:::::ssss::::::se::::::::e          " << endl;
    cout << "   GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee       P::::::::P        a:::::aaaa::::::a u:::::::::::::::us::::::::::::::s  e::::::::eeeeeeee  " << endl;
    cout << "     GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e       P::::::::P         a::::::::::aa:::a uu::::::::uu:::u s:::::::::::ss    ee:::::::::::::e  " << endl;
    cout << "        GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee       PPPPPPPPPP          aaaaaaaaaa  aaaa   uuuuuuuu  uuuu  sssssssssss        eeeeeeeeeeeeee  " << endl;
    cout << "                                                                                                                                                                                  " << endl;
}
void gameover() {
    cout << " _______    ________   ___ __ __   ______       ______   __   __   ______   ______       " << endl;
    cout << "/______/\  /_______/\ /__//_//_/\ /_____/\     /_____/\ /_/\ /_/\ /_____/\ /_____/\      " << endl;
    cout << "\::::__\/__\::: _  \ \\::\| \| \ \\::::_\/_    \:::_ \ \\:\ \\ \ \\::::_\/_\:::_ \ \     " << endl;
    cout << " \:\ /____/\\::(_)  \ \\:.      \ \\:\/___/\    \:\ \ \ \\:\ \\ \ \\:\/___/\\:(_) ) )_   " << endl;
    cout << "  \:\\_  _\/ \:: __  \ \\:.\-/\  \ \\::___\/_    \:\ \ \ \\:\_/.:\ \\::___\/_\: __ `\ \  " << endl;
    cout << "   \:\_\ \ \  \:.\ \  \ \\. \  \  \ \\:\____/\    \:\_\ \ \\ ..::/ / \:\____/\\ \ `\ \ \ " << endl;
    cout << "    \_____\/   \__\/\__\/ \__\/ \__\/ \_____\/     \_____\/ \___/_(   \_____\/ \_\/ \_\/ " << endl;
    cout << "                                                                                         " << endl;
}

int main() {

    initscr();
    noecho();

    game = newwin(20, 110, 5, 5);
    Game game1(game);
        
    game1.play();
}