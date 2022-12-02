#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
#include "Apple.h"
#include "Game.h"
#include <cmath>
using namespace std;

string mainPage(SDL_Plotter& g)
{
    string return_comand = 'null';

    vector<textbox> test;

    return return_comand;
}

int main(int argc, char **argv)
{

    SDL_Plotter g(650, 900);
    Snake s(2);
    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));

    char key;
    Game gm(s,a);



    gm.initSounds(g);
    g.Sleep(3000);
    while(!g.getQuit()){
        gm.playClassicSnake(g);
    }

    return 0;
}
