#include "grid_screen.h"



grid_screen::grid_screen(size_t new_height, size_t new_width)
{
    for (size_t y = 0; y < new_height; y++)
    {
        for (size_t x = 0; x < new_width; x++)
        {
            if (!((y > 0) && (y < new_height - 1)))
            {
                m_grid += SYMBOL_EDGE;
            }
            else
            {
                if (!((x > 0) && (x < new_width - 1)))
                {
                    m_grid += SYMBOL_EDGE;
                }
                else
                {
                    m_grid += SYMBOL_NULL;
                }
            }
        }

        m_grid += "\n";
    }

    m_grid_cache = m_grid;
    m_width = new_width;
    m_height = new_height;
}

void grid_screen::set_point(size_t new_x, size_t new_y, char new_symbol)
{
    if ((new_x > 0) && (new_x < m_width - 1) && (new_y > 0) && (new_y < m_height))
    {
        m_grid[str_coord_2d(new_x, (m_height - 1) - new_y, m_width)] = new_symbol;  //the reason for "(m_height - 1) - new_y" is to reverse y input
    }
}

size_t grid_screen::get_width()
{
    return m_width;
}

size_t grid_screen::get_height()
{
    return m_height;
}

//universal for both windows and linux terminals
void grid_screen::print_grid()
{
#ifdef __linux__ 
    system("clear");
#elif _WIN32
    system("CLS");
#else
#endif

    std::cout << m_grid;
}

void grid_screen::refresh_grid()
{
    m_grid = m_grid_cache;
}

grid_screen::~grid_screen()
{
}

//this function is for calculating 2d input coordinates to 1d string
size_t grid_screen::str_coord_2d(size_t x, size_t y, size_t line_len)
{
    return ((line_len * y) + x + y);
}
