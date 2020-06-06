// simple C program for Runge-Kutta of fourth order
// @author BivasKumar

#include <stdio.h>
#include <math.h>

double f(double xv, double yv)
{
    return (0.5 - xv - pow(yv, 2)) / (pow(xv, 2) + yv + 1);
}

int main()
{
    double x0, y0, xn, h;

    printf("Enter value of x0 and y0 = ");
    scanf("%lf%lf", &x0, &y0);

    printf("Enter value of h = ");
    scanf("%lf", &h);

    printf("Enter value of x = ");
    scanf("%lf", &xn);

    double k1, k2, k3, k4, k;
    int n = (int)((xn - x0) / h);
    double x[n + 1], y[n + 1];
    x[0] = x0;
    y[0] = y0;
    for (int i = 0; i < n; i++)
    {
        x[i + 1] = x[i] + h;
    }
    int i = 0;
    for (i = 0; i < n + 1; i++)
    {
        k1 = h * f(x[i], y[i]);
        k2 = h * f((x[i] + (h / 2.0)), (y[i] + (k1 / 2.0)));
        k3 = h * f((x[i] + (h / 2.0)), (y[i] + (k2 / 2.0)));
        k4 = h * f((x[i] + h), (y[i] + k3));
        k = (k1 + (2 * k2) + (2 * k3) + k4) * (1.0 / 6.0);
        y[i + 1] = y[i] + k;
    }
    printf("\nO.D.E : dy/dx = (0.5 - x + y^2) / (x^2 + y +1)\n");
    printf("\nUsing Runge-Kutta of fourth order, y(%lf) = %.7lf", xn, y[i]);
    return 0;
}
