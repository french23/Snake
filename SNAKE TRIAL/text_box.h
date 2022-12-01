#ifndef TEXT_BOX_H_INCLUDED
#define TEXT_BOX_H_INCLUDED

#include <string>
#include <vector>
#include "symbol.h"

using namespace std;

class textBox {
    private:
        string fontName = "font.txt";
        vector<symbols> text;
        string inputStr;
    public:
        textBox(Point, int, string);
        bool isClicked(Point mouseLoc);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
};




#endif // TEXT_BOX_H_INCLUDED
