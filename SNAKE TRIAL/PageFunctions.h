#ifndef PAGEFUNCTIONS_H_INCLUDED
#define PAGEFUNCTIONS_H_INCLUDED

/*
* Author: Benjamin Szabo, Peter Stuart
* Assignment Title: Snake Game
* Assignment Description: Create a snake game
* Due Date: 12/7/2022
* Date Created: 12/1/2022
* Date Last Modified: 12/7/2022
 */

#include <iostream>
#include "Apple.h"
#include "Game.h"
#include "text_box.h"
#include <cmath>

using namespace std;

/*
 * description: displays and controls the main page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string mainPage(SDL_Plotter& g, const int WIDTH, const int HIGHT);

/*
 * description: displays and controls the game over page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string gameOverPage(SDL_Plotter& g, const int WIDTH, const int HIGHT, int score);

/*
 * description: displays and controls the pause page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/

string pauseGamePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

/*
 * description: displays and controls the saves page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string saveGamePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

/*
 * description: displays and controls the successful load page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string successLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

/*
 * description: displays and controls the failed load page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string failedLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

/*
 * description: load for x amount of time
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: takes the amount of time passed to load
 *
*/
string load_time(SDL_Plotter& g, int load_time, const int WIDTH, const int HEIGHT);

/*
 * description: cover the page in a specific color
 * return: void
 * precondition: plotter and color given
 * postcondition: screen is a solid color
 *
*/
void fill_screen_with_color(SDL_Plotter& g, color background_color,const int& WIDTH, const int& HIGHT);

/*
 * description: displays the controls page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string controlsPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

/*
 * description: displays the game mode selection page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string gameModes(SDL_Plotter& g, const int WIDTH, const int HEIGHT);


/*
 * description: displays the Set Score page
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string SetScorePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT, Game& gm, string initials);

/*
 * description: displays the amazing makers of the game
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string creditPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

/*
 * description: displays top scores
 * return: string
 * precondition: plotter is given and width and hight
 * postcondition: a command is given to main
 *
*/
string topScore(SDL_Plotter& g, const int WIDTH, const int HEIGHT, Game& gm);

#endif // PAGEFUNCTIONS_H_INCLUDED
