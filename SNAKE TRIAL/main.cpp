#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
using namespace std;

int main(int argc, char **argv)
{
    SDL_Plotter g(650, 900);
    Snake s(4);
    char key;
    s.getSegment(0).setX(650/2);
    s.getSegment(0).setY(900/2);


    while(!g.getQuit()){
        if(g.kbhit()){
           key = g.getKey();
           s.setDirection(key);
        }
        s.eraseSnake(g);
        s.drawSnake(g);
        g.Sleep(125);
        g.update();
    }
    return 0;
}
