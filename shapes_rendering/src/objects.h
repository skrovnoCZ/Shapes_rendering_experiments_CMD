#ifndef __OBJECTS__
#define __OBJECTS__

#include <iostream>
#include <vector>
#include "grid_screen.h"

#define SYMBOL_NO_COLLIDE '-'
#define SYMBOL_COLLIDE '!'

#define OBJECT_RECTANGLE 'R'
#define OBJECT_CIRCLE 'C'

class objects
{
protected:
    std::vector<float> m_coords_x;
    std::vector<float> m_coords_y;
    std::vector<float> m_radius;    //circle
    grid_screen* m_p_grid;
    size_t m_count;
    size_t m_grid_width;
    size_t m_grid_height;
public:
    objects();
    virtual void configure_grid(grid_screen* p_grid);
    virtual void make_object(float new_x, float new_y);
    virtual void render_objects() = 0;
    virtual void set_object_coords(size_t object, float new_x, float new_y);
    virtual ~objects();
};

#endif