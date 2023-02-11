#ifndef __OBJECTS__
#define __OBJECTS__

#include <iostream>
#include <vector>
#include "grid_screen.h"

#define SYMBOL_NO_COLLIDE '-'
#define SYMBOL_COLLIDE '!'

class objects
{
private:
    std::vector<float> m_coords_x;
    std::vector<float> m_coords_y;
    std::vector<float> m_width;
    std::vector<float> m_height;
    std::vector<bool> m_no_collide;
    size_t m_object_count;
    grid_screen* m_p_grid;
    size_t m_grid_width;
    size_t m_grid_height;
public:
    objects();
    void configure_grid(grid_screen* p_grid);
    void make_object_rectangle(float new_x, float new_y, float new_width, float new_height);
    void object_collide_rectangle();
    void render_objects();
    void set_object_coords(size_t object, float new_x, float new_y);
    size_t get_object_count();
    ~objects();
};

#endif