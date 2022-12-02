#include "Game.h"

using namespace std;

///Constructors///
Game::Game(){
    s = Snake();
    a = Apple();
    score = 0;
    gameOver = false;
    isPaused = false;
    isReset = false;

}
Game::Game(Snake snk, Apple app){
    s = snk;
    a = app;

    score = 0;
    gameOver = false;
    isPaused = false;
    isReset = false;
}

///Accessors ///
Snake Game::getSnake() const{
    return s;
}
Apple Game::getApple()const{
    return a;
}
int   Game::getScore() const{
    return score;
}
bool  Game::getGameCond()const{
    return gameOver;
}
bool  Game::getIsPaused(){
    return isPaused;
}
char  Game::getKey(){
    return key;
}

///Mutators///
void Game::setSnake(const Snake snk){
    s = snk;
}
void Game::setApple(const Apple app){
    a = app;
}
void Game::setScore(const int s){
    score = s;
}
void Game::setGameCond(const bool b){
    gameOver = b;
}
void Game::incrementScore(){
    score++;
}
void Game::setPause(const bool b){
    isPaused = b;
}
void Game::setKey(const char c){
    key = c;
}

///Methods///
void Game::checkBoarderCollision(SDL_Plotter& g){

    if(s.getSegment(0).getX() == 0 || s.getSegment(0).getX() == g.getCol()){
        g.playSound("SnakeDie.wav");
        s.setSnakeDeath(true); /// End Game
    }
    else if(s.getSegment(0).getY() == 0 || s.getSegment(0).getY() == g.getRow()){
        g.playSound("SnakeDie.wav");
        s.setSnakeDeath(true); /// End Game
    }

}
void Game::playClassicSnake(SDL_Plotter& g){
    ///Resets game
    if(isReset){
        resetGame(g);
    }
    ///Keyboard detection
    if(g.kbhit()){
        key = g.getKey();
        s.setDirection(g, key);
        switch(key){
            case 'p': isPaused = !isPaused; /// 'p' pauses game
                    break;
            case 'r': isReset = true;
        }
    }
    if(!s.isSnakeDead() && !isPaused){
        ///Apple Collision
        if(a.checkAppleCollision(s)){
            a.eraseApple(g);
            a.setPoint(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25)));
            s.incrementLength();
            g.playSound("SnakeMunchSound.wav");
            score++;

        }

        /// Self and wall collision
        s.checkSelfColision(g);
        checkBoarderCollision(g);

        /// Draw snake and apple
        a.drawApple(g);
        if(!s.isSnakeDead()){
            s.eraseSnake(g);
            s.drawSnake(g);
        }


        /// Update
        g.Sleep(125);
        g.update();
    }
}
void Game::resetGame(SDL_Plotter& g){
    g.clear();

    //Reset length
    s.setLength(2);

    //Reset snake and apple points
    s.setSegment( Segment(25, Point((650 / 2), (900 / 2))) , 0);
    s.setSegment( Segment(25, Point((650 / 2 + 25), (900 / 2 + 25))) , 1);
    a.setPoint(Point(((rand() % (825/ 25)) * 25), ((rand() % (575/ 25)) * 25)));

    //Reset Conditionals
    isReset = false;
    s.setSnakeDeath(false);
    score = 0;
    s.setDirection(RIGHT);
    key = rightKey;



}

void Game::initSounds(SDL_Plotter& g){
    /// Initializing Sounds
    g.initSound("SnakeMunchSound.wav");
    g.initSound("SnakeLeftTurn.wav");
    g.initSound("SnakeRightTurn.wav");
    g.initSound("SnakeGoUp.wav");
    g.initSound("SnakeGoDown.wav");
    g.initSound("SnakeDie.wav");

}
