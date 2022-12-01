#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED
#include "Snake.h"

using namespace std;

class Apple{
    private:
        Segment appSeg;
        bool beenHit;
        int R, G, B;
        int appleSize = 25;
    public:
        /// Constructors ///
        Apple();
        Apple(int size, Point p, int r = 255, int g = 2, int b = 2);

        /// Accessors ///
        Segment getSegment();
        bool hasBeenHit();
        int getAppleSize();
        int getR();
        int getG();
        int getB();

        /// Mutators ///
        void setSegment(const Segment);
        void setPoint(const Point);
        void setColor(int, int, int);
        void setAppleColision(const bool);


        /// Methods ///
        bool checkAppleCollision(Snake);
        void drawApple(SDL_Plotter&);
        void eraseApple(SDL_Plotter&);
};

#endif // APPLE_H_INCLUDED
