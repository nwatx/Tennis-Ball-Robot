#include <iostream>
#include <cmath>
int main()
{
    double initialX = 1;
    double initialY = 1;
    double initialHeadingRad = (M_PI / 180.0) * -30;

    //flipped signs and trig because if you actually draw the triangle it works out
    double additionalX = 60 * cos(initialHeadingRad);
    double additionalY = 60 * sin(initialHeadingRad);

    double finalX = initialX + additionalX;
    double finalY = initialY + additionalY;
    std::cout << "finalX: " << finalX << "\nfinalY: " << finalY;
}