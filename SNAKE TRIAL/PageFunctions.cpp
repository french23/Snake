#include "PageFunctions.h"

string mainPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT)
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
    textBox exit(Point(450,600),10,"EXIT");

    fill_screen_with_color(g,background_color, WIDTH, HEIGHT);

    background_color.R = 75;
    background_color.G = 32;
    background_color.B = 102;

    title.draw(g);
    play.draw(g,border_color,background_color);
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

    }

    return return_comand;
}

string gameOverPage(SDL_Plotter& g, const int WIDTH, const int HEIGHT)
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

void fill_screen_with_color(SDL_Plotter& g, color background_color,const int& WIDTH, const int& HEIGHT)
{
    for(int x = 0; x < HEIGHT; x++)
    {
        for(int y = 0; y < WIDTH; y++)
        {
            g.plotPixel(x,y,background_color);
        }
    }
}
