#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Snake.h"
#include "SDL_Plotter.h"
#include "Apple.h"
using namespace std;

class Game{
    private:
        Snake s;
        Apple a;

        int score;
        bool gameOver;
    public:
        ///Constructors///
        Game();
        Game(Snake snk = Snake(), Apple app = Apple());

        ///Accessors ///
        Snake getSnake()const;
        Apple getApple()const;
        int getRow()const;
        int getCol()const;
        int getScore() const;
        bool getGameCond()const;

        ///Mutators///
        void setSnake(const Snake snk);
        void setApple(const Apple app);
        void setScore(const int s);
        void incrementScore();
        void setGameCond(const bool b);

        ///Methods///
        void checkBoarderCollision(SDL_Plotter& g);
        void playClassicSnake(SDL_Plotter& g);
        void resetGame(SDL_Plotter& g);





};


#endif // GAME_H_INCLUDED
