// simple C program for Trapezoidal rule
// @author BivasKumar

#include <stdio.h>
#include <math.h>

double fx(double x)
{
    return sqrt((1.0 - (0.75 * pow(x, 2))) / (1.0 - pow(x, 2)));
}

int main()
{
    int n;
    printf("\nNumber of sub-intervlas(any) = ");
    scanf("%d", &n);
    double x[n + 1], y[n + 1];
    double a, b;
    printf("\nLower-limit & Upper-limit = ");
    scanf("%lf%lf", &a, &b);
    double h = (b - a) / (double)n;
    double sum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a;
        y[i] = fx(x[i]);
        a += h;
    }
    for (int i = 1; i < n; i++)
    {
        sum += y[i];
    }
    double integral = h * (((y[0] + y[n]) / 2) + sum);
    printf("\nIntegrand-\n\t");
    printf("[(1 - 0.75x^2) / (1 - x^2)]^1/2\n");
    printf("\nUsing Trapezoidal Rule, Integral = %lf", integral);
    return 0;
}