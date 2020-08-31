#include "borderColorPicker.h"
#include <cmath>

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    /* your code here */
    this->borderSize = borderSize;
    this->fillColor = fillColor;
    this->img = img;
    this->tolerance = tolerance;
}

HSLAPixel borderColorPicker::operator()(point p)
{
    /* your code here */
    int height = img.height();
    int width = img.width();
    int b = borderSize;
    int bSq = b*b;
    int x = p.x;
    int y = p.y;
    for (int i = x-b; i <= x+b; i++){
      for (int j = y-b; j <= y+b; j++) {
        int dist = pow(i-x,2) + pow(j-y,2);
        if (dist <= bSq){
          if (i >= width || j >= height || i < 0 || j < 0) {
            return fillColor;
          } else if (img.getPixel(p.c.x,p.c.y)->dist(*(img.getPixel(i,j))) > tolerance){
            return fillColor;
          }
        }
      }
    }
    return *(img.getPixel(p.x,p.y));
}
