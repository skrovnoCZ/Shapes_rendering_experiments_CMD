#ifndef __RECTANGLES__
#define __RECTANGLES__

#include "objects.h"

class rectangles : public objects
{
private:
    std::vector<float> m_width;
    std::vector<float> m_height;
public:
    rectangles();
    void set_parameters(float new_width, float new_height);
    void render_objects() override;
    ~rectangles();
};

#endif