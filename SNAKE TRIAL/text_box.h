#ifndef TEXT_BOX_H_INCLUDED
#define TEXT_BOX_H_INCLUDED

#include <string>
#include <vector>
#include "symbol.h"

using namespace std;

class textBox {
    private:
        string fontName = "font.txt";
        vector<symbol> text;
        string inputStr;
        Point startLoc;
        int fontSize;
    public:
        textBox(Point, int, string);
        bool isClicked(Point);
        void draw(SDL_Plotter& g);
        void draw(SDL_Plotter& g, color border_color);
        void eraseText(SDL_Plotter&, color);
};




#endif // TEXT_BOX_H_INCLUDED
