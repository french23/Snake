#include "symbol.h"

symbol::symbol(string fileName, char input_symbol, int fount_size, Point starting_location)
{
    m_fileName = fileName;
    m_input_symbol = input_symbol;
    m_starting_location = starting_location;
    m_fount_size = fount_size;

    parse_and_fill_file();
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

        // All the colors stored now
        while(input_str != "endOfFile")// or keep_going)
        {
            if(input_str == "Symbol")
            {
                // Now check to see if the symbols match up
                file >> input_str;

                if(input_str[0] == m_input_symbol)
                {

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
    }

    file.close();
}

void symbol::draw_symbol(SDL_Plotter& g)
{
    grid_square canvas(m_size, m_fount_size, m_starting_location);

    for(int i = 0; i < m_v_sqr_points.size(); i++)
    {
        canvas.color_sqr(m_v_sqr_points[i],m_v_sqr_colors[i],g);
    }
}

void symbol::erase_symbol(SDL_Plotter& g, color background_color)
{
     grid_square canvas(m_size, m_fount_size, m_starting_location);
    for(int i = 0; i < m_v_sqr_points.size(); i++)
    {
        canvas.color_sqr(m_v_sqr_points[i], background_color,g);
    }
}

int symbol::get_size() const
{
    return m_size;
}
