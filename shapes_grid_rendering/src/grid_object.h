#ifndef __GRID_OBJECT__
#define __GRID_OBJECT__

#include <iostream>
#include <map>
#include "grid_screen.h"

class grid_object
{
private:
    std::map<size_t, float>m_coord_x;  //ID, coord x
    std::map<size_t, float>m_coord_y;  //ID, coord y
    std::map<size_t, std::vector<size_t>> m_ids_assigned;   //specific ID, all assigned IDs //TODO: use better method to mabe prevent ID assignment duplicity
    
    grid_screen* m_p_grid;  //to be able to use functions of screen
    size_t m_grid_width;    //to speed up getting screen dimensions
    size_t m_grid_height;   //to speed up getting screen dimensions
    //TODO: remove because object shouldn't even know about these things
    //      (if object coordinates are outside of screen limit then a different library should deal with this problem and not the object itself)
public:
    grid_object();
    void configure_grid(grid_screen* p_grid);
    void add_coord(float new_x, float new_y);
    void set_coord(size_t new_id, float new_x, float new_y);
    float get_coord_x(size_t new_id);
    float get_coord_y(size_t new_id);
    size_t get_coord_count();
    void render_object();
    void list_ids();
    void list_assigned_ids();
    void assign_coord(size_t id_first, size_t id_second);
    ~grid_object();
private:
    void calculate_line(float new_x_source_0, float new_y_source_0, float new_x_dist, float new_y_dist);
};

#endif