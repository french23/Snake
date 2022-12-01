#include "symbol.h"

symbol::symbol(string fileName, char input_symbol, int fount_size, Point starting_location)
{
    //cout << "inside of symbol constuctor" << endl; system("PAUSE");

    m_fileName = fileName;
    m_input_symbol = input_symbol;
    m_starting_location = starting_location;
    m_fount_size = fount_size;

    //cout << "about to enter the parse_and_fill_file function" << endl; system("PAUSE");
    parse_and_fill_file();
    //cout << "just finished the parse_and_fill_file function" << endl; system("PAUSE");

   /* cout << "about to asighn m_canvas to the return val of the constuctor" << endl; system("PAUSE");
    m_canvas = grid_square(m_size, m_fount_size, starting_location);
    cout << "finished setting m_canvas" << endl; system("PAUSE");*/
}

void symbol::parse_and_fill_file()
{
    ifstream file;
    string input_str;
    int input_int;
    color temp_color;
    bool keep_going = true;

    file.open(m_fileName);
    if(file.is_open())
    {
        //cout << "file is open" << endl;
        //system("PAUSE");
        // Takes in "Size"
        file >> input_str;
        // take in m_size
        file >> m_size;
        //cout << "the size of the segment array is(m_size) = " << m_size << endl;
        //system("PAUSE");

        // Now going to store all the colors

        //clear the color vector and fill it with a blank color
        m_colors.clear();
        temp_color.R = 255;
        temp_color.G = 255;
        temp_color.B = 255;
        m_colors.push_back(temp_color);

        // Loop though all the colors
        file >> input_str;
        //cout << "Now going to check for colors, input is = " << input_str << endl;
        //system("PAUSE");

        while(keep_going)
        {
            if(input_str == "Color")
            {
                // Take in the number thoughawway
                file >> input_str;

                // Take in R
                file >> input_int;
                temp_color.R = input_int;
                //cout << "the R vaule is = " << input_int << endl;
                //system("PAUSE");

                // Take in G
                file >> input_int;
                temp_color.G = input_int;
                //cout << "the G vaule is = " << input_int << endl;
                //system("PAUSE");

                // Take in B
                file >> input_int;
                temp_color.B = input_int;
                //cout << "the B vaule is = " << input_int << endl;
                //system("PAUSE");

                m_colors.push_back(temp_color);

                // Find the next input and check, if this isn't color then we don't want to update input_str
                file >> input_str;
            }
            else
            {
                keep_going = false;
            }

        }

        // Reset keep_going to use in the next loop
        keep_going = true;

        //cout << "all the colors are stored, the input_str should be letter, but it is = " << input_str<< endl;
        //system("PAUSE");

        // All the colors stored now
        while(input_str != "endOfFile")// or keep_going)
        {
            //cout << "entered the loop to look for letters" << endl;
            //cout << "input_str = " << input_str << endl;
            //system("PAUSE");
            if(input_str == "Symbol")
            {
                // Now check to see if the symbols match up
                file >> input_str;

                //cout << "Now checking to see if the symbols match up, input_str = " << input_str << endl;
                //system("PAUSE");

                if(input_str[0] == m_input_symbol)
                {
                    //cout << "found the correct letter!!!" << endl;
                    //system("PAUSE");

                    // This is the right letter, yay

                    // Loop though all though all the points
                    // X
                    for(int i = 0; i < m_size;i++)
                    {
                        // Y
                        for(int j = 0; j < m_size;j++)
                        {
                            file >> input_int;

                            // Need to loop though all of the colors to check
                            for(int k = 1; k < m_colors.size();k++)
                            {
                                // Checks to see if the color is what was passed in
                                if(input_int == k)
                                {
                                    // Store the location of the segment
                                    m_v_sqr_points.push_back(Point(j,i));
                                    // Store the color of the segment - this is equal in index to the point vector
                                    m_v_sqr_colors.push_back(m_colors[k]);
                                }
                            }
                        }
                    }
                    // At this point the loop is over so set keep_going to false;
                    keep_going = true;
                }
            }
            // Read the next input
            file >> input_str;
        }
        // << "exited the file, either end of the file or found the letter" << endl;
        //system("PAUSE");

    }

    file.close();
}

void symbol::draw_symbol(SDL_Plotter& g)
{
    grid_square canvas(m_size, m_fount_size, m_starting_location);
    /*cout << "about to enter the loop to print the symbole, should loop " << m_v_sqr_colors.size() << "times" << endl;
    system("PAUSE");*/
    for(int i = 0; i < m_v_sqr_points.size(); i++)
    {
        canvas.color_sqr(m_v_sqr_points[i],m_v_sqr_colors[i],g);
    }
    //cout << "Just finshed drawing the loop" << endl; system("PAUSE");
}
