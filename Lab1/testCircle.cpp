#include <iostream>
#include <string>
#include "Circle.h"

int main()
{
    std::string sep = "===============";

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

    std::cout << sep << sep << sep << std::endl;
    std::cout << sep << " Translate Test " << sep << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Translating Circle c2 - c2.translateXY(20, 4)" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Expected = [ x= 10, y= 9, radius= 2]" << std::endl;
    c2.translateXY(20, 4);
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Translating Circle c2 - c2.translateXY(-20, -4)" << std::endl;
    std::cout << "Translating Circle c2 - c2.translateXY(-30, 10)" << std::endl;
    std::cout << "Translating Circle c2 - c2.translateXY(60, 10)" << std::endl;
    std::cout << "Translating Circle c2 - c2.translateXY(40, 60)" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Expected = [ x= 60, y= 85, radius= 2]" << std::endl;
    c2.translateXY(-20, -4);
    c2.translateXY(-30, 10);
    c2.translateXY(60, 10);
    c2.translateXY(40, 60);
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Translating Circle c2 - c2.translateXY(40, 60)" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Expected = [ x= -20, y= 95, radius= 2]" << std::endl;
    c2.translateXY(-80, 10);
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;

    std::cout << sep << sep << sep << std::endl;
    std::cout << sep << " Intersection Test " << sep << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "c1 intersects c3" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "c1 = ";
    c1.displayCircle();
    std::cout << "c3 = ";
    c3.displayCircle();
    std::cout << "Expected = True" << std::endl;
    std::cout << "Actual = " << c1.intersect(c3) << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Class count = " << c1.getNumberofCurrentCircles() << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "c2 intersects c3" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "c2 = ";
    c2.displayCircle();
    std::cout << "c3 = ";
    c3.displayCircle();
    std::cout << "Expected = False" << std::endl;
    std::cout << "Actual = " << c2.intersect(c3) << std::endl;

    std::cout << sep << sep << sep << std::endl;
    std::cout << sep << " Radius Change Test " << sep << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Changing the radius of c2 to 50" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Current = " << c2.getRadius() << std::endl;
    c2.setRadius(50);
    std::cout << "Expected = 50" << std::endl;
    std::cout << "Actual = " << c2.getRadius() << std::endl;

    std::cout << sep << sep << sep << std::endl;
    std::cout << sep << " Compute Area Test " << sep << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Computing the area of c2" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "c2 = ";  
    c2.displayCircle();
    std::cout << "Expected = 7853.98" << std::endl;
    std::cout << "Actual = " << c2.computeArea() << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "Computing the area of c1" << std::endl;
    std::cout << sep << sep << sep << std::endl;
    std::cout << "c1 = ";
    c1.displayCircle();
    std::cout << "Expected = 314.16" << std::endl;
    std::cout << "Actual = " << c1.computeArea() << std::endl;

}
