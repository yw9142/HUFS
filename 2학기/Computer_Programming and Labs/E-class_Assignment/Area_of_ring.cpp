#include <iostream>

using namespace std;

double circleArea(double radius);

double Area_of_ring(double Outter_Circle, double Inner_Circle);

int main(void) {
    double Circle1 = circleArea(15);
    double Circle2 = circleArea(2);
    cout << Circle1 << '\n' << Circle2 << endl;

    double areaofring = Area_of_ring(Circle2, Circle1); // if Inner_Circle is bigger than Outter_Circle
    cout << "if Inner_Circle is bigger than Outter_Circle : " << areaofring << endl;
    areaofring = Area_of_ring(Circle1, Circle2); // if Outter_Circle is bigger than Inner_Circle
    cout << "if Outter_Circle is bigger than Inner_Circle : " << areaofring << endl;

    return (0);
}

double circleArea(double radius) {
    return (3.1415926 * radius * radius);
}

double Area_of_ring(double Outter_Circle, double Inner_Circle) {
    if (Outter_Circle < Inner_Circle)
        return (Inner_Circle - Outter_Circle);
    else
        return (Outter_Circle - Inner_Circle);
}