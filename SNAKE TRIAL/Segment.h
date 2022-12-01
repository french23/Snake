#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED

#include "Point.h"
#include "SDL_Plotter.h"
using namespace std;
class Segment{
    private:
        int segS;
        Point p;

    public:
        //Constructors
        Segment();
        Segment(int, Point);

        // Accessors
        int getSize() const;
        Point getPoint() const;
        int getX();
        int getY();
        //Mutators
        void setSize(const int);
        void setPoint(const Point);
        void setX(int);
        void setY(int);

        // Methods
        void draw(SDL_Plotter&, int r = 0, int g = 0, int b = 0);
        void draw(SDL_Plotter&, color input_color);


};
#endif // SEGMENT_H_INCLUDED
