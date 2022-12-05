/*
* Author: Benjamin Szabo, Peter Stuart
* Assignment Title: Snake Game
* Assignment Description: Create a snake game
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/5/2022
 */

#include "text_box.h"

textBox::textBox(Point loc, int fontSize, string text){
    inputStr = text;
    char inputChar;
    Point tempPoint;

    startLoc = loc;
    this->fontSize = fontSize;

    for(int i = 0; i < inputStr.size(); i++){
        inputChar = inputStr.at(i);
        tempPoint.setX(startLoc.getX() + fontSize * 7.5 * i);
        tempPoint.setY(startLoc.getY());
        this->text.push_back(symbol(fontName, inputChar, fontSize, tempPoint));
    }
}

bool textBox::isClicked(Point mouseLoc){
    bool withinRange = false;
    int x, x2;
    int y, y2;
    int checkX, checkY;

    checkX = mouseLoc.getX();
    checkY = mouseLoc.getY();

    x = startLoc.getX();
    x2 = (startLoc.getX() * 7.5 * text.size()+ text.at(0).get_size() * fontSize);
    y = startLoc.getY();
    y2 = (startLoc.getY() + text.at(0).get_size() * fontSize);

    if((checkX >= x && checkX <= x2) &&
       (checkY >= y && checkY <= y2)){
        withinRange = true;
       }
}

void textBox::draw(SDL_Plotter& g){
    for(int i = 0; i < text.size(); i++){
        text.at(i).draw_symbol(g);
    }
}

void textBox::eraseText(SDL_Plotter& g, color backgroundColor){
    for(int i = 0; i < text.size(); i++){
        text.at(i).erase_symbol(g, backgroundColor);
    }
}
