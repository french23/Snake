
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
    //x2 = (startLoc.getX() * 7.5 * text.size()+ text.at(0).get_size() * fontSize);
    x2 = startLoc.getX() + ((text[0].get_size() * fontSize)* (text.size()));
    y = startLoc.getY();
    y2 = (startLoc.getY() + text.at(0).get_size() * fontSize);

    /*cout << "size of x2 is " << x2 << endl;
    cout << "size of y2 is " << y2 << endl; system("pause");*/

    if((checkX >= x && checkX <= x2) &&
       (checkY >= y && checkY <= y2)){
        withinRange = true;
       }

    return withinRange;
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

void textBox::draw(SDL_Plotter& g, color border_color)
{
    int x = startLoc.getX();
    int x2 = startLoc.getX() + ((text[0].get_size() * fontSize)* (text.size()));
    int y = startLoc.getY();
    int y2 = (startLoc.getY() + text.at(0).get_size() * fontSize);

    // Draw horizontal lines
    for(int i = x; i <= x2; i++)
    {
        g.plotPixel(i, y-2, border_color);
        g.plotPixel(i, y-1, border_color);
        g.plotPixel(i, y, border_color);

        g.plotPixel(i, y2, border_color);
        g.plotPixel(i, y2+1, border_color);
        g.plotPixel(i, y2+2, border_color);
    }

    // Draw vertical lines
    for(int i = y; i <= y2; i++)
    {
        g.plotPixel(x-2, i, border_color);
        g.plotPixel(x-1, i, border_color);
        g.plotPixel(x, i, border_color);

        g.plotPixel(x2, i, border_color);
        g.plotPixel(x2+1, i, border_color);
        g.plotPixel(x2+2, i, border_color);
    }

    this->draw(g);
}

void textBox::draw(SDL_Plotter& g, color border_color, color background_color)
{
    int x = startLoc.getX();
    int x2 = startLoc.getX() + ((text[0].get_size() * fontSize)* (text.size()));
    int y = startLoc.getY();
    int y2 = (startLoc.getY() + text.at(0).get_size() * fontSize);

    for(int i = x; i < x2; i++)
    {
        for(int j = y; j < y2; j++)
        {
            g.plotPixel(i,j,background_color);
        }
    }

    this->draw(g,border_color);
}
