// simple C program for Lagrange's Interpolation
// @author Bivas_Kumar

#include <stdio.h>

int main()
{
    double x[25], y[25];
    double ip, sum = 0, t;
    int n;
    printf("Enter number of data points = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%lf", &y[i]);
    }
    printf("\nEnter the interpolating point = ");
    scanf("%lf", &ip);
    for (int i = 0; i < n; i++)
    {
        t = y[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                t *= (ip - x[j]) / (x[i] - x[j]);
        }
        sum += t;
    }
    printf("\nTable-\n");
    printf("\n\tX");
    for (int i = 0; i < n; i++)
    {
        printf("\t%lf", x[i]);
    }
    printf("\n\tF(X)");
    for (int i = 0; i < n; i++)
    {
        printf("\t%lf", y[i]);
    }
    printf("\nUsing Lagrange's Interpolation, f[%lf] = %lf", ip, sum);
    return 0;
}