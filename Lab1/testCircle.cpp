#include <iostream>
#include "Circle.h"

int main()
{
    Circle c1;
    c1.displayCircle();
    std::cout << c1.getNumberofCurrentCircles() << std::endl;

    Circle c2 = Circle(-20, 7, 4);
    c2.displayCircle();
    std::cout << c2.getNumberofCurrentCircles() << std::endl;
    std::cout << c1.intersect(c2) << std::endl;
}
