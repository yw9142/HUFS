#include <stdio.h>
#include <math.h>

#define PI 3.14

int     volume(float radius)
{
    return ((4.0f * (PI) * radius * radius * radius) / (3.0f));
}   

int     main(void)
{
    float radius;
    
    radius = 10;
    float result;
    result = volume(radius);

    printf("%f", result);
}