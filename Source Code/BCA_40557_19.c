// simple C program for Regula-Falsi Method
// @author Bivas_Kumar

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return pow(x, 3) - 5 * pow(x, 2) + 10;
}

void regulaFalsi(double a, double b, double EPSILON)
{
    if (f(a) * f(b) >= 0)
    {
        printf("\nroot can't lie between %lf & %lf", a, b);
    }
    double c;
    while (fabs(a - b) >= EPSILON)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == (double)0)
        {
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    printf("\nroot using Reugla-Falsi Method, x = %.8lf", c);
}

int main()
{
    double a, b, e;
    printf("\ninterval = ");
    scanf("%lf%lf", &a, &b);
    printf("\nerror threshold = ");
    scanf("%lf", &e);
    printf("\nequation : x^3 - 5x^2 + 10 = 0");
    regulaFalsi(a, b, e);
    return 0;
}