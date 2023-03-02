/*
*   This is a non-universal library for rendering objects do grid_screen.
*   It is getting vertice values from vertice_obj.
*
*/

#ifndef __OBJECT_RENDERER__
#define __OBJECT_RENDERER__

#include "grid_screen.h"
#include "vertice_obj.h"

class object_renderer
{
private:
    grid_screen *m_p_screen;
public:
    object_renderer(grid_screen* new_p_screen);
    void render_object(vertice_obj &new_object);
    ~object_renderer();
private:
    void calculate_line(double new_x_source_0, double new_y_source_0, double new_x_dist, double new_y_dist);
    void log_output(std::string new_type, std::string new_message);
};

#endif