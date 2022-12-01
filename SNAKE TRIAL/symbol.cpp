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
    file.open(m_fileName);
    if(file.is_open())
    {
        // Takes in "Size"
        cin >> input_str;
        // take in m_size
        cin >> m_size;
        //pick up here

    }
}
