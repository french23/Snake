#include "Letter.h"


Letter::Letter()
{
    m_font_size = 15;
    m_name = 'A';
    m_box_size = 8;
    m_starting_location = Point_T(0,0);
}

/*
* description: sets up the letter,
* return: none
* precondition: none
* postcondition: makes the letter
*
*/
Letter::Letter(int font_size, char name, int box_size, Point_T starting_location)
{
    m_font_size = font_size;
    m_name = name;
    m_box_size = box_size;
    m_starting_location = starting_location;
}

/*
* description: draws the letter
* return: none
* precondition: takes in the location of the letter
* postcondition: draws the letter
*
*/
void Letter::draw_letter(string file_name, SDL_Plotter& g)
{
    fstream input_file;
    input_file.open(file_name);
    string input_string;
    color my_color;

    grid_square my_grid(m_box_size, m_font_size, m_starting_location);


    if(input_file.is_open())
    {
        cout << "file is open" << endl;
        while(input_string != "endOfLine ")
        {
            cout << "In the loop - ";
            cout << input_string << endl;
            system("PAUSE");
            getline(input_file, input_string, ' ');
            if(input_string == "letter")
            {
                cout << "is a letter" << endl;
                getline(input_file, input_string);
                if(input_string.size() == 1 and input_string[0] == m_name)
                {
                    cout << "is the letter " << m_name << endl;
                    //Take in the letter R
                    getline(input_file, input_string, ' ');
                    //Take in the R number
                    getline(input_file, input_string, ' ');
                    my_color.R = stoi(input_string);

                    //Take in the letter G
                    getline(input_file, input_string, ' ');
                    //Take in the G number
                    getline(input_file, input_string, ' ');
                    my_color.G = stoi(input_string);

                    //Take in the letter B
                    getline(input_file, input_string, ' ');
                    //Take in the B number
                    getline(input_file, input_string, ' ');
                    my_color.B = stoi(input_string);

                    // Start the loop to print the letter
                    getline(input_file, input_string, ' ');

                    while(input_string != "endLetter")
                    {
                        cout << "in the loop for endLetter search" << endl;
                        // Check if a number and then plot if so
                        if(isdigit(input_string[0]))
                        {
                            cout << "in the digit if statment" << endl;
                            // Store the x
                            Point_T temp_point;
                            temp_point.setX(stoi(input_string));

                            // Get and store y
                            getline(input_file, input_string);
                            temp_point.setY(stoi(input_string));

                            // Plot square
                            my_grid.color_sqr(temp_point,my_color,g);
                            // TEMP DELTE ME
                            g.update();
                        }
                        else if(input_string == "R")
                        {
                            getline(input_file, input_string);
                            my_color.R = stoi(input_string);
                        }
                        else if(input_string == "G")
                        {
                            getline(input_file, input_string);
                            my_color.G = stoi(input_string);
                        }
                        else if(input_string == "B")
                        {
                            getline(input_file, input_string);
                            my_color.B = stoi(input_string);
                        }

                        // Now that the operation is done, getline agian for the loop
                        getline(input_file, input_string, ' ');
                    }
                }
            }
        }
    }
    input_file.close();
}
