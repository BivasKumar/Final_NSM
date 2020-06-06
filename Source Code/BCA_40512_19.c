// simple C program for Simpson's 1/3 rule
// @author BivasKumar

#include <stdio.h>
#include <math.h>

double f(int i, double a, double h)
{
    double x = a + (i * h);
    return 1.0 / (pow(x, 2) - 2 * x + 3);
}

int main()
{
    int n;
    double a, b, h;
    double sum = 0;
    double integral;
    printf("lower-limit & upper-limit  = ");
    scanf("%lf%lf", &a, &b);
    printf("\nnumber of sub-intervals(must be even) = ");
    scanf("%d", &n);
    h = (b - a) / (double)n;
    printf("\ncomputed step-size, h = %lf", h);
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum = 2 * f(i, a, h);
        else
            sum = 4 * f(i, a, h);
    }
    sum += f(0, a, h) + f(n, a, h);
    integral = sum * (h / 3.0);
    printf("\nintegrand = 1/(X^2 - 2X + 3)");
    printf("\nintegral = %lf", integral);
    return 0;
}