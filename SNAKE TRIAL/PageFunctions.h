#ifndef PAGEFUNCTIONS_H_INCLUDED
#define PAGEFUNCTIONS_H_INCLUDED
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
string gameOverPage(SDL_Plotter& g, const int WIDTH, const int HIGHT);

/*
 * description: cover the page in a specific color
 * return: void
 * precondition: plotter and color given
 * postcondition: screen is a solid color
 *
*/
void fill_screen_with_color(SDL_Plotter& g, color background_color,const int& WIDTH, const int& HIGHT);











///START NEW STUFF BEN///
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

string successLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);

string failedLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT);
///END NEW STUFF BEN///

#endif // PAGEFUNCTIONS_H_INCLUDED
