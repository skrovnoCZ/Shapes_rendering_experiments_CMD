#ifndef __CUSTOM_FUNCTIONS__
#define __CUSTOM_FUNCTIONS__

#include <chrono>
#include <string>

#define M_PI 3.14159265358979323846
#define DELAY_NS 15625000.0 //test value

std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<__int64, std::ratio<1, 1000000000>>> cust_current_time = std::chrono::high_resolution_clock::now();
std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<__int64, std::ratio<1, 1000000000>>> cust_previous_time = std::chrono::high_resolution_clock::now();

bool real_timer(double nanosec)
{
    cust_current_time = std::chrono::high_resolution_clock::now();

    if ((double)std::chrono::duration_cast<std::chrono::nanoseconds>(cust_current_time - cust_previous_time).count() >= nanosec)
    {
        cust_previous_time = std::chrono::high_resolution_clock::now();
        return true;
    }
    else
    {
        return false;
    }
}

//vertice movement calculation around rotating center
void vertice_center_rotate(double center_x, double center_y, double &vert_x, double &vert_y, double degrees) //angle input should be wanted angle - current angle
{
    double radians = (degrees * M_PI) / 180.000000;
    double x1 = 0.000000;
    double y1 = 0.000000;
    double x2 = 0.000000;
    double y2 = 0.000000;

    x1 = vert_x - center_x;
    y1 = vert_y - center_y;

    x2 = (x1 * cos(radians)) - (y1 * sin(radians));
    y2 = (x1 * sin(radians)) + (y1 * cos(radians));

    vert_x = x2 + center_x;
    vert_y = y2 + center_y;
}

    #ifdef MATH_FUNCT_REQUEST
    //rounding to desired decimal points
    double cunstom_round(double number, size_t dec_point)
    {
        std::string rounding_string = "1";
        double rounding = 0.0;
    
        for (size_t i = 0; i < dec_point; i++)
        {
            rounding_string += "0";
        }
    
        rounding = stod(rounding_string);
    
        return floor(number * rounding + 0.5) / rounding;
    }
    
    double rad(double degrees)
    {
        return (degrees * M_PI) / 180.0;
    }
    #endif
#endif