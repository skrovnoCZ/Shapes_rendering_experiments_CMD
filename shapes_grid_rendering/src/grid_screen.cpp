#include "grid_screen.h"
#include <Windows.h>
#include <string>



grid_screen::grid_screen(size_t new_height, size_t new_width)
{
    m_inicialise = false;
    std::string string_x;

    string_x.resize(new_width, SYMBOL_NULL);

    std::vector<std::string> string_temp(new_height, string_x);
    m_grid = string_temp;

    refresh_grid();

    m_width = 0;
    m_height = m_grid.size();

    for (size_t i = 0; i < m_grid.size(); i++)
    {
        if (m_grid.at(i).size() > m_width)
        {
            m_width = m_grid.at(i).size();
        }
    }

    m_inicialise = true;
}

void grid_screen::set_symbol(char new_symbol, size_t new_y, size_t new_x)
{
    m_grid[new_y][new_x] = new_symbol;
}

size_t grid_screen::get_width()
{
    return m_width;
}

size_t grid_screen::get_height()
{
    return m_height;
}

void grid_screen::print_grid()
{
    system("CLS");

    for (int i = m_grid.size() - 1; i > -1; i--)
    {
        std::cout << m_grid.at((size_t)i) << std::endl;
    }
}

void grid_screen::refresh_grid()
{
    if (m_inicialise)
    {
        std::string string_x;

        string_x.resize(m_width, SYMBOL_NULL);

        std::vector<std::string> string_temp(m_height, string_x);
        m_grid = string_temp;
    }

    for (size_t y = 0; y < m_grid.size(); y++)
    {
        for (size_t x = 0; x < m_grid.at(y).size(); x++)
        {
            if (!((y > 0) && (y < (m_grid.size() - 1))))
            {
                m_grid[y][x] = SYMBOL_WALL;
            }
            else if (!((x > 0) && (x < (m_grid.at(y).size() - 1))))
            {
                m_grid[y][x] = SYMBOL_WALL;
            }
        }
    }
}

grid_screen::~grid_screen()
{
}