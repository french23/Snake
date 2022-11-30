#include "Game.h"

using namespace std;

///Constructors///
Game::Game(){
    s = Snake();
    a = Apple();
    score = 0;
    gameOver = false;
}
Game::Game(Snake snk, Apple app){
    s = snk;
    app = app;
    score = 0;
    gameOver = false;
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


///Methods///
void Game::checkBoarderCollision(SDL_Plotter& g){

    if(s.getSegment(0).getX() == 0 || s.getSegment(0).getX() == g.getCol()){
        g.playSound("SnakeDie.wav");
        s.setSnakeDeath(true); /// End Game
    }
    else if(s.getSegment(0).getX() == 0 || s.getSegment(0).getY() == g.getRow()){
        g.playSound("SnakeDie.wav");
        s.setSnakeDeath(true); /// End Game
    }

}
void Game::playClassicSnake(SDL_Plotter& g){
    bool isPaused = false;
    char key;
    s.setSegment(Segment(25, Point(900/2, 650/2)), 0);
    s.setSegment(Segment(25, Point(900/2 + 25, 650/2 + 25)), 1);


        if(!isPaused){
            if(a.checkAppleCollision(s)){
                a.eraseApple(g);
                a.setPoint(Point(rand() % 825, rand() % 575));
                s.incrementLength();

            }
            if(g.kbhit()){
               key = g.getKey();
               s.setDirection(g, key);
            }

            s.checkSelfColision(g);
            checkBoarderCollision(g);
            if(s.isSnakeDead()){
                isPaused = true;

            }
            if(!isPaused){
                s.eraseSnake(g);
                s.drawSnake(g);
            }


            a.drawApple(g);
            g.Sleep(125);
            g.update();
        }

}
void Game::resetGame(SDL_Plotter& g){

}


