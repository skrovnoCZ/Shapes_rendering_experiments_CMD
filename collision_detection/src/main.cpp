#include <iostream>
#include "objects.h"

int main() {
    grid_screen* p_screen = new grid_screen(101, 101);
    objects all_objects;

    float coord_x = 50.0f;
    float coord_y = 70.0f;
    bool end_detected_x = false;
    bool end_detected_y = false;

    all_objects.configure_grid(p_screen);
    //-------------------------------(x_pos, y_pos, width, height))
    all_objects.make_object_rectangle(coord_x, coord_y, 6.0f, 8.0f);
    all_objects.make_object_rectangle(73.0f, 93.0f, 8.0f, 8.0f);
    all_objects.make_object_rectangle(56.0f, 70.0f, 6.0f, 8.0f);
    all_objects.make_object_rectangle(55.0f, 74.0f, 4.0f, 8.0f);
    all_objects.make_object_rectangle(10.0f, 43.0f, 8.0f, 8.0f);
    all_objects.make_object_rectangle(25.0f, 27.0f, 8.0f, 8.0f);
    all_objects.make_object_rectangle(20.0f, 20.0f, 10.0f, 10.0f);
    all_objects.make_object_rectangle(26.0f, 26.0f, 10.0f, 10.0f);
    all_objects.make_object_rectangle(43.0f, 10.0f, 8.0f, 8.0f);

    for (size_t i = 0; i < 1000; i++)
    {
        if (coord_x < 70.0f && end_detected_x)
        {
            coord_x++;
        }
        else if (coord_y < 90.0f && end_detected_y)
        {
            coord_y++;
        }
        else if (coord_x > 20.0f)
        {
            coord_x--;
            end_detected_x = false;
        }
        else if (coord_y > 30.0f)
        {
            coord_y--;
            end_detected_y = false;
        }
        else
        {
            end_detected_x = true;
            end_detected_y = true;
        }

        all_objects.set_object_coords(0, coord_x, coord_y);
        all_objects.render_objects();
        all_objects.object_collide_rectangle();
        p_screen->print_grid();
    }

    all_objects.render_objects();
    all_objects.object_collide_rectangle();

    p_screen->print_grid();

    delete p_screen;
    p_screen = nullptr;

    return 0;
}
