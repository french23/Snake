#include <iostream>
#include "Segment.h"
#include "SDL_Plotter.h"
#include "Snake.h"
#include "grid_square.h"
#include "Apple.h"
#include "Game.h"
#include "text_box.h"
#include "PageFunctions.h"
#include <cmath>
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 1200;

int main(int argc, char **argv)
{

    SDL_Plotter g(WIDTH, HEIGHT);
    string command = "main page";
    string input;
    Snake s(2);
    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    char key;
    Game gm(s,a);

    gm.initSounds(g);
    g.Sleep(300);

    while(!g.getQuit())
    {
        //cout << "in the while loop" << endl; system("pause");
        ///Main Page
        if(command == "main page")
        {
            input = mainPage(g, WIDTH, HEIGHT);
            if(input == "start game")
            {
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "exit")
            {
                g.setQuit(true);
            }
        }

        ///Classic Snake Game
        else if(command == "play snake")
        {
            gm.playClassicSnake(g);
            if(gm.getGameCond())
            {
                command = "game over";
                //cout << "game over" << endl;
            }
        }

        ///Losing Screen
        else if(command == "game over")
        {
            input = gameOverPage(g, WIDTH, HEIGHT);

            if(input == "play again")
            {
                command = "play snake";
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
            }
            //return to main page
            else if(input == "main page")
            {
                command = "main page";
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
            }
        }

        g.update();
    }

    return 0;
}
