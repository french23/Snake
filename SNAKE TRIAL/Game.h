#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Snake.h"
#include "SDL_Plotter.h"
#include "Apple.h"
#include <fstream>

using namespace std;

class Game{
    private:
        Snake s;
        Apple a;
        int score;
        bool gameOver;
        bool isPaused;
        bool isReset;
        char key;
        ifstream fileRead;
        ofstream filePush;

        int highScores[11];
        string highScoreNames[11];

    public:
        ///Constructors///
        Game();
        Game(Snake snk, Apple app );

        ///Accessors ///
        Snake getSnake()const;
        Apple getApple()const;
        int getRow()const;
        int getCol()const;
        int getScore() const;
        bool getGameCond()const;
        bool getIsPaused()const;
        char getKey()const;
        int* getHighScores();

        ///Mutators///
        void setSnake(const Snake snk);
        void setApple(const Apple app);
        void setScore(const int s);
        void incrementScore();
        void setPause(const bool b);
        void setKey(const char c);

        ///Methods///
        void checkBoarderCollision(SDL_Plotter& g);
        void playClassicSnake(SDL_Plotter& g);
        void resetGame(SDL_Plotter& g);
        void initSounds(SDL_Plotter& g);

        ///Methods regarding save/load game
        void saveGame(string fName);
        bool loadGame(string fName);

        ///Methods regarding HighScore
        void readHighScores(string fName);
        void setHighScores(string fName, string username);


};


#endif // GAME_H_INCLUDED
