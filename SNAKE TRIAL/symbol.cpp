#include "symbol.h"

symbol::symbol(string fileName, char input_symbol, SDL_Plotter& g)
{
    m_fileName = fileName;
    m_input_symbol = input_symbol;
    parse_and_fill_file();
}

grid_square symbol::parse_and_fill_file()
{
    ifstream file;
    string input_str;
    int input_int;
    color temp_color;
    bool keep_going = true;

    file.open(m_fileName);
    if(file.is_open())
    {
        // Takes in "Size"
        file >> input_str;
        // take in m_size
        file >> m_size;

        // Now going to store all the colors

        //clear the color vector and fill it with a blank color
        m_colors.clear();
        temp_color.R = 255;
        temp_color.G = 255;
        temp_color.B = 255;
        m_colors.push_back(temp_color);

        // Loop though all the colors
        file >> input_str;

        while(keep_going)
        {
            if(input_str == "Color")
            {
                // Take in the number thoughawway
                file >> input_str;

                // Take in R
                file >> input_int;
                temp_color.R = input_int;

                // Take in G
                file >> input_int;
                temp_color.G = input_int;

                // Take in B
                file >> input_int;
                temp_color.B = input_int;

                m_colors.push_back(temp_color);
            }
            else
            {
                keep_going = false;
            }

            file >> input_str;
        }

        // All the colors stored now
        while(input_str != "endOfFile")
        {
            if(input_str == "Letter")
            {
                // Now check to see if the symbols match up
                input_str = file.get();
                if(input_str[0] == m_input_symbol)
                {
                    // This is the right letter, yay
                    for(int i = 0; i < m_size;i++)
                    {
                        for(int j = 0; j < m_size;j++)
                        {
                            file >> input_int;
                            if() // PICK UP HERE DOING THE LOOP TO FILL THE GRID SQUARE
                        }
                    }
                }
            }
        }




    }
}
