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
#include <ctime>
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
    bool first_time = true;
    int start_title_music_time;
    const int title_music_time = 37;
    char key;
    Game gm(s,a);

    gm.initSounds(g);
    g.initSound("gameover.mp3");
    g.initSound("highscore.mp3");
    g.initSound("uibuttonclick2.mp3");

    g.Sleep(300);

    while(!g.getQuit())
    {
        //cout << "in the while loop" << endl; system("pause");
        ///Main Page
        if(command == "main page")
        {

            // Loop the music
            if(first_time)
            {

                //cout << "about to play sound file" << endl; system("pause");
                g.initSound("TITLESCREEN.mp3");
                g.Sleep(100);
                g.playSound("TITLESCREEN.mp3");
                start_title_music_time = time(0);
                first_time = false;
            }
            else
            {
                if(time(0) - title_music_time > start_title_music_time)
                {
                    start_title_music_time = time(0);
                    g.playSound("TITLESCREEN.mp3");
                }
            }

            input = mainPage(g, WIDTH, HEIGHT);
            if(input == "start game")
            {
                first_time = true;
                g.quitSound("TITLESCREEN.mp3");
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "exit")
            {
                g.setQuit(true);
            }
            else if(input == "load saved"){
                if(gm.loadGame("save1")){
                    first_time = true;
                    g.quitSound("TITLESCREEN.mp3");
                    command = "loaded game";
                }
                else{
                    command = "failed load";
                }
            }
        }

        ///Classic Snake Game
        else if(command == "play snake")
        {
            gm.playClassicSnake(g);

            if(gm.getIsPaused()){
                command = "pause game";
            }

            if(gm.getGameCond())
            {
                command = "game over";
                //cout << "game over" << endl;
            }
        }

        else if(command == "pause game"){
            fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
            input = pauseGamePage(g, WIDTH, HEIGHT);

            if(input == "resume game")
            {

                command = "play snake";
                gm.setPause(false);
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);

            }
            else if(input == "reset game")
            {
                command = "play snake";
                gm.setPause(false);
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
            }
            else if(input == "save game")
            {
                gm.setPause(false);
                gm.saveGame("save1");
                command = "save screen";

            }
            else if(input == "main page")
            {
                command = "main page";
                gm.setPause(false);
                gm.resetGame(g);
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
            }
        }

        else if(command == "save screen"){
            input = saveGamePage(g, WIDTH, HEIGHT);
            if(input == "clicked"){
                command = "pause game";
            }
        }

        else if(command == "loaded game"){
            input = successLoadPage(g, WIDTH, HEIGHT);
            if(input == "clicked"){
                command = "play snake";
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);

            }
        }

        else if(command == "failed load"){
            input = failedLoadPage(g, WIDTH, HEIGHT);
            if(input == "clicked"){
                command = "main page";
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
