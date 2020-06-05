// simple C program for Gauss-Seidel Method
// @author Bivas_Kumar

#include <stdio.h>
#include <math.h>

float fx(float y, float z)
{
    return (14.0 - 5.0 * y + 2.0 * z) / 20.0;
}

float fy(float x, float z)
{
    return (17.0 - 3.0 * x - z) / 10.0;
}

float fz(float x, float y)
{
    return (23.0 - x + 4.0 * y) / 10.0;
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
    printf("\n\t20x - 5y - 2z = 14");
    printf("\n\t3x + 10y + z = 17");
    printf("\n\tx - 4y + 10z = 23");
    printf("\n\nRoots are-\n");
    printf("\n\tx = %.4f\n\ty = %.4f\n\tz = %.4f", x, y, z);
    return 0;
}