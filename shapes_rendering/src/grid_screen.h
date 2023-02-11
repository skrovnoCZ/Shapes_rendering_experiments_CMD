#ifndef __GRID_SCREEN__
#define __GRID_SCREEN__

#include <iostream>
#include <vector>
#include <string>

#define SYMBOL_POINT 'O'
#define SYMBOL_TEXTURE (char)177
#define SYMBOL_WALL (char)219
#define SYMBOL_NULL ' '

class grid_screen
{
private:
    std::vector<std::string> m_grid;
    size_t m_width;
    size_t m_height;
    bool m_inicialise;
public:
    grid_screen(size_t new_height, size_t new_width);
    void set_symbol(char new_symbol, size_t new_y, size_t new_x);
    size_t get_width();
    size_t get_height();
    void print_grid();
    void refresh_grid();
    ~grid_screen();
};

#endif