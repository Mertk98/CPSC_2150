#include <iostream>
#include "Circle.h"

int main()
{
    Circle c1;
    Circle c2 = Circle(-10, 5, 2);
    Circle c3 = Circle(5, 1, 3);

    std::cout << "c1 = ";
    c1.displayCircle();
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << "c3 = ";
    c3.displayCircle();
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;

    c2.translateXY(20, 4);
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;

    c2.translateXY(-20, -4);
    c2.translateXY(-30, 10);
    c2.translateXY(60, 10);
    c2.translateXY(60, 10);
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;
}
