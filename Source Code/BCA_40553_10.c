// simple C program for Gauss-Seidel Method
// @author Bivas_Kumar

#include <stdio.h>
#include <math.h>

float fx(float y, float z)
{
    return (20.5 - 1.1 * y - 2.2 * z) / 6.7;
}

float fy(float x, float z)
{
    return (22.9 - 3.1 * x + 1.5 * z) / 9.4;
}

float fz(float x, float y)
{
    return (28.8 - 2.1 * x + 1.5 * y) / 8.4;
}

int main()
{
    float x, y, z;
    float tx, ty, tz;
    float ex, ey, ez;
    float e;
    printf("Enter initial values of x, y and z = ");
    scanf("%f%f%f", &x, &y, &z);
    printf("Enter error threshold = ");
    scanf("%f", &e);
    do
    {
        tx = fx(y, z);
        ty = fy(tx, z);
        tz = fz(tx, ty);
        ex = fabs(x - tx);
        ey = fabs(y - ty);
        ez = fabs(z - tz);
        x = tx;
        y = ty;
        z = tz;
    } while (ex > e && ey > e && ez > e);
    printf("\nsystem of equations-\n");
    printf("\n\t6.7x + 1.1y + 2.2z = 20.5");
    printf("\n\t3.1x + 9.4y - 1.5z = 22.9");
    printf("\n\t2.1x - 1.5y + 8.4z = 28.8");
    printf("\n\nRoots are-\n");
    printf("\n\tx = %.3f\n\ty = %.3f\n\tz = %.3f", x, y, z);
    return 0;
}