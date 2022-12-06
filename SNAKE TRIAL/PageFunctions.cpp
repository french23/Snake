#include "PageFunctions.h"

string mainPage(SDL_Plotter& g, const int WIDTH, const int HIGHT)
{
    string return_comand = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox title(Point(250,50),15,"SNAKE!");
    textBox play(Point(450,200),10,"PLAY");
    ///START NEW///
    textBox loadSaved(Point(220,320),10,"LOAD SAVED");
    ///END NEW///
    textBox exit(Point(450,600),10,"EXIT");

    fill_screen_with_color(g,background_color, WIDTH, HIGHT);

    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    title.draw(g);
    play.draw(g,border_color,background_color);
    ///START NEW///
    loadSaved.draw(g,border_color,background_color);
    ///END NEW///
    exit.draw(g,border_color,background_color);

    if(g.mouseClick())
    {
        point temp = g.getMouseClick();

        // check all textboxes and see if they were clicked
        if(exit.isClicked(Point(temp.x,temp.y)))
        {
            return_comand = "exit";
        }
        else if(play.isClicked(Point(temp.x,temp.y)))
        {
            return_comand = "start game";
        }
        ///START NEW///
        else if(loadSaved.isClicked(Point(temp.x,temp.y))){
            return_comand = "load saved";
        }
        ///END NEW///

    }

    return return_comand;
}

string gameOverPage(SDL_Plotter& g, const int WIDTH, const int HIGHT)
{
    string return_comand = "null";color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    color background_color;
    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    textBox gameOver(Point(100,200),13,"GAME OVER!");
    textBox play_again(Point(300,320),8,"PLAY AGAIN");
    textBox main_page(Point(340,440),8,"MAIN PAGE");

    gameOver.draw(g);
    play_again.draw(g, border_color, background_color);
    main_page.draw(g, border_color, background_color);

    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(play_again.isClicked(Point(temp.x,temp.y)))
        {
            return_comand = "play again";
        }
        else if(main_page.isClicked(Point(temp.x,temp.y)))
        {
               return_comand = "main page";
        }
    }

    return return_comand;
}

void fill_screen_with_color(SDL_Plotter& g, color background_color,const int& WIDTH, const int& HIGHT)
{
    for(int x = 0; x < HIGHT; x++)
    {
        for(int y = 0; y < WIDTH; y++)
        {
            g.plotPixel(x,y,background_color);
        }
    }
}


///START NEW STUFF BEN///
string pauseGamePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    color background_color;
    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    textBox pauseGame(Point(100, 75),13,"PAUSE GAME");
    textBox resumeGame(Point(250,220),8,"RESUME GAME");
    textBox resetGame(Point(275,340),8,"RESET GAME");
    textBox saveGame(Point(300,460),8,"SAVE GAME");
    textBox mainPage(Point(300,580),8,"MAIN PAGE");


    pauseGame.draw(g);
    resumeGame.draw(g, border_color, background_color);
    resetGame.draw(g, border_color, background_color);
    saveGame.draw(g, border_color, background_color);
    mainPage.draw(g, border_color, background_color);

    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(resumeGame.isClicked(Point(temp.x,temp.y)))
        {
            g.Sleep(100);
            return_command = "resume game";
        }
        else if(resetGame.isClicked(Point(temp.x,temp.y)))
        {
            return_command = "reset game";
        }
        else if(saveGame.isClicked(Point(temp.x,temp.y)))
        {
            return_command = "save game";

        }
        else if(mainPage.isClicked(Point(temp.x,temp.y)))
        {
            return_command = "main page";
        }
    }

    return return_command;
}

string saveGamePage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox saveGame(Point(175, 300),10, "GAME SAVED!");
    textBox okay(Point(450,500),8,"OKAY");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
    saveGame.draw(g);
    okay.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(okay.isClicked(Point(temp.x,temp.y)))
        {
            return_command = "clicked";
        }
    }

    return return_command;

}

string successLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox loadedGame(Point(175, 300),10, "LOADED GAME!");
    textBox play(Point(450,500),8,"PLAY");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
    loadedGame.draw(g);
    play.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(play.isClicked(Point(temp.x,temp.y)))
        {
            return_command = "clicked";
        }
    }

    return return_command;
}

string failedLoadPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT){
    string return_command = "null";
    color background_color;
    background_color.R = 55;
    background_color.G = 2;
    background_color.B = 82;

    color border_color;
    border_color.R = 227;
    border_color.G = 27;
    border_color.B = 190;

    textBox loadedGame(Point(75, 300),10, "NO SAVED DATA!");
    textBox mainPage(Point(300,500),8,"MAIN PAGE");

    fill_screen_with_color(g, background_color, WIDTH, HEIGHT);
    loadedGame.draw(g);
    mainPage.draw(g, border_color, background_color);


    if(g.mouseClick())
    {
        point temp = g.getMouseClick();
        if(mainPage.isClicked(Point(temp.x,temp.y)))
        {
            return_command = "clicked";
        }
    }

    return return_command;
}


///END NEW STUFF BEN///
