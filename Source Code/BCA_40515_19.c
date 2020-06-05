// simple C program for Newton-Raphson Method
// @author Bivas_Kumar

#include <stdio.h>
#include <math.h>

// error threshold
#define EPSILON 0.0000001

// function of x f(x)
double f(double x)
{
    return (2 * x * sin(x) - cos(x));
}

// derivative of f(x)
double df(double x)
{
    return (2 * x * cos(x) + 3 * sin(x));
}

void newtonRaphson(double a, double b)
{
    // check for wrong interval
    if (f(a) * f(b) >= 0)
    {
        printf("\nroot can't lie between %lf and %lf", a, b);
        return;
    }

    double next_x, curr_x, h;

    // curr_x will take the non-zero value closest to 0
    curr_x = (fabs(f(a)) < fabs(f(b))) ? ((a == 0) ? b : a) : ((b == 0) ? a : b);

    // if absolute value of h is less than EPSILON
    // then subtracting h from the inital approximation or curr_x
    // will result in the next approximation or next_x
    // such that next_x ~= curr_x
    // the above termintaion conditon is deprecated (visit the link below)
    // https://math.stackexchange.com/questions/3132871/stopping-criterion-for-newton-raphson
    // but for simplicity we'll use it
    do
    {
        // h = f(xn) / f'(xn)
        h = f(curr_x) / df(curr_x);

        // xn+1 = xn - h
        next_x = curr_x - h;

        // update the curr_x with next_x for next iteration
        curr_x = next_x;
    } while (fabs(h) >= EPSILON);

    printf("\nby the Method of Newton-Raphson, x = %lf", curr_x);
}

int main()
{
    double a, b;
    printf("\ninterval = ");
    scanf("%lf%lf", &a, &b);
    newtonRaphson(a, b);
    return 0;
}