#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "Segment.h"
using namespace std;


//const char upKey    = UP_ARROW;
//const char downKey  = DOWN_ARROW;
//const char leftKey  = LEFT_ARROW;
//const char rightKey = RIGHT_ARROW;

const char upKey    = 'w';
const char downKey  = 's';
const char leftKey  = 'a';
const char rightKey = 'd';






const int MAX_SIZE = 100;
const int SIZE = 25;


enum Direction {UP, DOWN, LEFT, RIGHT};
class Snake{
    private:
        int length;
        Segment seg[MAX_SIZE];
        bool isDead;
        Direction dir;
        int R,G,B;
        char key, prevKey;


    public:
        /// Constructors ///
        Snake();
        Snake(int size, int red = 0, int green = 0, int blue = 0);

        /// Accessors ///
        int getLength() const;
        Segment getSegment(int i);
        bool isSnakeDead() const;
        Direction getDirection() const;

        /// Mutators ///
        void setLength(const int);
        void incrementLength();
        void setSegment(const Segment, const int);
        void setSnakeDeath(const bool);
        void setDirection(const Direction);
        void setDirection(SDL_Plotter& g, char k);

        /// Methods ///
        void checkSelfColision(SDL_Plotter& g);
        void drawSnake(SDL_Plotter&);
        void eraseSnake(SDL_Plotter&);
        void initSounds(SDL_Plotter& g);




};

#endif // SNAKE_H_INCLUDED
