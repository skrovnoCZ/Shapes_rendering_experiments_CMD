#include <iostream>
#include "rectangles.h"
#include "circles.h"

using namespace std;

int main()
{
    float coord_x = 30.0f;
    float coord_y = 37.0f;
    bool end_detected_x = false;
    bool end_detected_y = false;

    grid_screen* p_screen = new grid_screen(75, 75);
    objects* p_rectangles = new rectangles();
    objects* p_circles = new circles();

    p_rectangles->configure_grid(p_screen);
    p_rectangles->make_object(10.0f, 15.0f);
    dynamic_cast<rectangles*>(p_rectangles)->set_parameters(5.0f, 10.0f);

    p_rectangles->make_object(27.0f, 43.0f);
    dynamic_cast<rectangles*>(p_rectangles)->set_parameters(11.0f, 23.0f);

    p_rectangles->make_object(46.0f, 55.0f);
    dynamic_cast<rectangles*>(p_rectangles)->set_parameters(25.0f, 14.0f);

    p_circles->configure_grid(p_screen);
    p_circles->make_object(coord_x, coord_y);
    dynamic_cast<circles*>(p_circles)->set_parameters(21.0f);

    p_circles->make_object(43.0f, 21.0f);
    dynamic_cast<circles*>(p_circles)->set_parameters(7.0f);

    while (true)
    {
        if (coord_x < 50.0f && end_detected_x)
        {
            coord_x++;
        }
        else if (coord_y < 70.0f && end_detected_y)
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

        p_screen->refresh_grid();
        p_circles->set_object_coords(0, coord_x, coord_y);

        p_rectangles->render_objects();
        p_circles->render_objects();

        p_screen->print_grid();
    }

    p_screen->print_grid();

    delete p_circles;
    p_circles = nullptr;
    delete p_rectangles;
    p_rectangles = nullptr;
    delete p_screen;
    p_screen = nullptr;

    return 0;
}
