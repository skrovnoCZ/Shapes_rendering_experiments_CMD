#ifndef __CIRCLES__
#define __CIRCLES__

#include "objects.h"

class circles : public objects
{
private:
    std::vector<float> m_radius;
public:
    circles();
    void set_parameters(float new_radius);
    void render_objects() override;
    ~circles();
};

#endif