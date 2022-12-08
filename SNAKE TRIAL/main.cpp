/*
* Author: Peter Whitcomb, Peter Stewart, Ben Szabo,
*          Logan Rigdon, Justin Yoo
* Assignment Title: Snake Game
* Assignment Description: Create the game Snake
* Due Date: 12/7/2022
* Date Created: 11/26/2022
* Date Last Modified: 12/7/2022
*/
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
    string gameMode;
    string initals = "___";
    Snake s(2);
    Apple a(25, Point(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25))));
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;
    bool first_time = true;
    int start_title_music_time;
    const int title_music_time = 37;
    Game gm(s,a);

    gm.initSounds(g);
    g.initSound("gameover.mp3");
    g.initSound("highscore.mp3");
    g.initSound("uibuttonclick2.mp3");

    load_time(g,2000,WIDTH,HEIGHT);

    while(!g.getQuit())
    {
        ///Main Page
        if(command == "main page")
        {
            // Loop the music
            if(first_time)
            {
                g.initSound("TITLESCREEN.mp3");
                load_time(g,1000,WIDTH,HEIGHT);
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
                command = "play menu";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "exit")
            {
                g.setQuit(true);
            }
            else if(input == "load saved")
            {
                if(gm.loadGame("save1"))
                {
                    remove("save1");
                    first_time = true;
                    g.quitSound("TITLESCREEN.mp3");
                    command = "loaded game";
                }
                else
                {
                    command = "failed load";
                }
            }
            else if(input == "top score")
            {
                gm.readHighScores("highScores.txt");
                command = "top scores";
            }
            else if(input == "controls")
            {
                command = "controls page";
            }
            else if(input == "credits")
            {
                command = "credits";
            }
        }

        ///credits page
        else if(command == "credits")
        {
            input = creditPage(g, WIDTH, HEIGHT);
            if(input == "main page")
            {
                command = "main page";
            }
        }

        ///Snake Game
        else if(command == "play menu")
        {
            input = gameModes(g, WIDTH, HEIGHT);

            if(input == "classic snake")
            {
                first_time = true;
                g.quitSound("TITLESCREEN.mp3");
                gameMode = input;
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "medium mode")
            {
                first_time = true;
                g.quitSound("TITLESCREEN.mp3");
                gameMode = input;
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "hard mode")
            {
                first_time = true;
                g.quitSound("TITLESCREEN.mp3");
                gameMode = input;
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "rampage mode")
            {
                first_time = true;
                g.quitSound("TITLESCREEN.mp3");
                gameMode = input;
                command = "play snake";
                fill_screen_with_color(g,background_color,WIDTH,HEIGHT);
            }
            else if(input == "clicked")
            {
                command = "main page";
            }
        }


        else if(command == "play snake")
        {

            if(gameMode == "classic snake")
            {
                gm.playClassicSnake(g);
            }
            else if(gameMode == "medium mode")
            {
                gm.mediumGamemode(g);
            }
            else if(gameMode == "hard mode")
            {
                gm.hardGamemode(g);
            }
            else if(gameMode == "rampage mode")
            {
                gm.RampageGamemode(g);
            }
            else if(gameMode == "clicked")
            {
                command = "main page";
            }

            if(gm.getIsPaused())
            {
                command = "pause game";
            }

            if(gm.getGameCond())
            {
                remove("save1");
                command = "game over";
                g.playSound("gameover.mp3");
            }
        }


        ///Pause Page
        else if(command == "pause game")
        {
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

        ///Save Page
        else if(command == "save screen")
        {
            input = saveGamePage(g, WIDTH, HEIGHT);
            if(input == "clicked")
            {
                command = "pause game";
            }
        }

        ///Loaded Game Page
        else if(command == "loaded game")
        {
            input = successLoadPage(g, WIDTH, HEIGHT);
            if(input == "clicked")
            {
                command = "play snake";
                if(gm.getGamemode() == "classic")
                {
                    gameMode = "classic snake";
                }
                else if(gm.getGamemode() == "medium")
                {
                    gameMode = "medium mode";
                }
                else if(gm.getGamemode() == "hard")
                {
                    gameMode = "hard mode";
                }
                else if(gm.getGamemode() == "rampage")
                {
                    gameMode = "rampage mode";
                }
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);

            }
        }

        ///Failed Load Page
        else if(command == "failed load")
        {
            input = failedLoadPage(g, WIDTH, HEIGHT);
            if(input == "clicked")
            {
                command = "main page";
            }
        }



        /// Controls page
        else if(command == "controls page")
        {
            input = controlsPage(g, WIDTH, HEIGHT);
            if(input == "clicked")
            {
                command = "main page";
            }
        }


        ///Game over
        else if(command == "game over")
        {
            int* my_array = gm.getHighScores();
            if(gm.getScore() > my_array[9])
            {
                command = "set score";
                initals = "___";
                g.Sleep(100);
            }
            else
            {
                command = "game over page";
            }
        }

        ///Game Over Page
        else if(command == "game over page")
        {
            input = gameOverPage(g, WIDTH, HEIGHT, gm.getScore());

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

        ///Set Score Screen
        else if(command == "set score")
        {
            input = SetScorePage(g, WIDTH, HEIGHT, gm, initals);
            if(input == "game over page")
            {
                command = "game over page";
                fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
            }
            else
            {
                initals = input;
            }
        }

        ///TOP SCORES
        else if(command == "top scores")
        {
            input = topScore(g, WIDTH, HEIGHT, gm);
            if(input == "clicked"){
                command = "main page";
            }
        }

        g.update();
    }

    return 0;
}
