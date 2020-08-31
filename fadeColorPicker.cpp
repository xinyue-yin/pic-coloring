#include "fadeColorPicker.h"
#include <cmath>

fadeColorPicker::fadeColorPicker(double fade)
{
    /* your code here */
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    /* your code here */
    HSLAPixel ret;
    ret.h = p.c.color.h;
    ret.s = p.c.color.s;
    double distSq = pow((int)p.x - (int)p.c.x, 2) + pow((int)p.y - (int)p.c.y,2);
    double dist = sqrt(distSq);
    ret.l = p.c.color.l * pow(fadeFactor, dist);
    return ret;
}
