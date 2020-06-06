// simple C program for Newton's backward Interpolation
// @author Bivas_Kumar

#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

double table[MAX_ROW][MAX_COL];

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void backwardDifference(int y)
{
    printf("\nEnter Y values-\n");
    for (int i = 0; i < y; i++)
    {
        printf("Y%d = ", i);
        scanf("%lf", &table[i][0]);
    }

    // outer loop for column
    // inner loop for row
    for (int i = 1; i < y; i++)
    {
        for (int j = i; j < y; j++)
        {
            table[j][i] = table[j][i - 1] - table[j - 1][i - 1];
        }
    }

    printf("\nBackward Difference Table-\n\n");
    // outer loop for row
    // inner loop for column
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (j <= i)
            {
                printf("\t%lf", table[i][j]);
            }
        }
        printf("\n");
    }
}

double backwardInterpolation(double x, double xn, double h, int y)
{
    double u = (x - xn) / h;
    double termU = 1, nablaY, term;
    double sum = table[y - 1][0];
    for (int i = 1; i < y; i++)
    {
        termU *= (u + i - 1);
        nablaY = table[y - 1][i];
        term = (termU * nablaY) / (double)factorial(i);
        sum += term;
    }
    return sum;
}

int main()
{
    double h, xn, x, f;
    int y;
    printf("\nnumber of Y values = ");
    scanf("%d", &y);

    printf("\ninterval 'h' = ");
    scanf("%lf", &h);

    printf("\nvalue of 'x%d' = ", y - 1);
    scanf("%lf", &xn);

    printf("\ninterpolation point 'x' = ");
    scanf("%lf", &x);

    backwardDifference(y);
    f = backwardInterpolation(x, xn, h, y);
    printf("\nUsing Newton's Backward Interpolation, f(%lf) = %.5lf", x, f);
    return 0;
}
