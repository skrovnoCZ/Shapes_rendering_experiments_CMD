#include <iostream>
#include <time.h>
#include <string>
#include "grid_object.h"

#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3

void move_randomizer(grid_object* p_object, grid_screen* p_screen)
{
    size_t random_id;
    srand((int)time(NULL));

    switch (rand() % 4)
    {
    case MOVE_UP:
        srand((int)time(NULL));
        random_id = rand() % p_object->get_coord_count() + 1;   //in range from first to last coord ID

        if ((int)p_object->get_coord_y(random_id) + 1 < p_screen->get_height() - 1)
        {
            p_object->set_coord(random_id, p_object->get_coord_x(random_id), p_object->get_coord_y(random_id) + 1.0f);
        }
        else
        {
            srand((int)time(NULL));
        }
        break;
    case MOVE_DOWN:
        srand(rand() % 3);
        random_id = rand() % p_object->get_coord_count() + 1;   //in range from first to last coord ID

        if ((int)p_object->get_coord_y(random_id) - 1 > 0)
        {
            p_object->set_coord(random_id, p_object->get_coord_x(random_id), p_object->get_coord_y(random_id) - 1.0f);
        }
        else
        {
            srand((int)time(NULL));
        }
        break;
    case MOVE_LEFT:
        srand((int)time(NULL));
        random_id = rand() % p_object->get_coord_count() + 1;   //in range from first to last coord ID

        if ((int)p_object->get_coord_x(random_id) - 1 > 0)
        {
            p_object->set_coord(random_id, p_object->get_coord_x(random_id) - 1.0f, p_object->get_coord_y(random_id));
        }
        else
        {
            srand((int)time(NULL));
        }
        break;
    case MOVE_RIGHT:
        srand(rand() % 3);
        random_id = rand() % p_object->get_coord_count() + 1;   //in range from first to last coord ID

        if ((int)p_object->get_coord_x(random_id) + 1 < p_screen->get_width() - 1)
        {
            p_object->set_coord(random_id, p_object->get_coord_x(random_id) + 1.0f, p_object->get_coord_y(random_id));
        }
        else
        {
            srand((int)time(NULL));
        }
        break;
    default:
        move_randomizer(p_object, p_screen);
        break;
    }
}



int main()
{
    grid_screen* p_screen = new grid_screen(119, 119);
    grid_object* p_object_0 = new grid_object();
    grid_object* p_object_1 = new grid_object();

    p_object_0->configure_grid(p_screen);   //TODO: use better method to prevent object knowing about grid screen and it's parameters
    p_object_1->configure_grid(p_screen);   //TODO: use better method to prevent object knowing about grid screen and it's parameters
    //TODO: make a library to use object's parameters (object's coordinates and line drawing calculations) to draw on screen

    //---------------square-------------
    p_object_0->add_coord(10.0f, 6.0f);     //auto ID 1
    p_object_0->add_coord(80.0f, 6.0f);     //auto ID 2
    p_object_0->add_coord(80.0f, 30.0f);    //auto ID 3
    p_object_0->add_coord(10.0f, 30.0f);    //auto ID 4

    p_object_0->assign_coord(1, 2);         //ID 1 with ID 2 etc.
    p_object_0->assign_coord(1, 3);
    p_object_0->assign_coord(1, 4);
    p_object_0->assign_coord(2, 1);
    p_object_0->assign_coord(2, 3);
    p_object_0->assign_coord(3, 1);
    p_object_0->assign_coord(3, 2);
    p_object_0->assign_coord(3, 4);
    p_object_0->assign_coord(4, 1);
    p_object_0->assign_coord(4, 3);
    //---------------square-------------

    //TODO: fix coord assignment method to prevent assigning one coordinate multiple times

    //---------------polygon-------------
    p_object_1->add_coord(20.0f, 40.0f);    //auto ID 1
    p_object_1->add_coord(40.0f, 40.0f);    //auto ID 2
    p_object_1->add_coord(30.0f, 60.0f);    //auto ID 3
    p_object_1->add_coord(40.0f, 80.0f);    //auto ID 4
    p_object_1->add_coord(20.0f, 80.0f);    //auto ID 5
    p_object_1->add_coord(7.0f, 60.0f);     //auto ID 6
    //p_object_1->add_coord(90.0f, 90.0f); //TODO: fix if no assignment so default assignment is 0 (0 is empty coord ID). crash because there is no coord with ID 0

    p_object_1->assign_coord(1, 2);         //ID 1 with ID 2 etc.
    p_object_1->assign_coord(1, 6);
    p_object_1->assign_coord(2, 1);
    p_object_1->assign_coord(2, 3);
    p_object_1->assign_coord(3, 2);
    p_object_1->assign_coord(3, 4);
    p_object_1->assign_coord(4, 3);
    p_object_1->assign_coord(4, 5);
    p_object_1->assign_coord(5, 4);
    p_object_1->assign_coord(5, 6);
    p_object_1->assign_coord(6, 1);
    p_object_1->assign_coord(6, 5);
    //---------------polygon-------------

    p_object_0->render_object();
    p_object_1->render_object();
    p_screen->print_grid();

    p_object_0->list_ids();
    std::cout << std::endl;
    p_object_0->list_assigned_ids();

    std::cout << std::endl;
    std::cout << std::endl;

    p_object_1->list_ids();
    std::cout << std::endl;
    p_object_1->list_assigned_ids();

    //--------START TEST---------------------
    std::string start;

    std::getline(std::cin, start);
    

    while (true)
    {
        move_randomizer(p_object_0, p_screen);
        move_randomizer(p_object_1, p_screen);

        p_screen->refresh_grid();
        p_object_0->render_object();
        p_object_1->render_object();
        p_screen->print_grid();
    }
    //--------END TEST-----------------------

    delete p_object_1;
    p_object_1 = nullptr;
    delete p_object_0;
    p_object_0 = nullptr;
    delete p_screen;
    p_screen = nullptr;

    return 0;
}
