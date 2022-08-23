/* This is a program to find the root of x^3 -3x +1=0 by fixed point iteration method */
#include <stdio.h>
#include <math.h>

double func(double x)
{
    double val = (3*x-1)/(x*x); // function in x=g(x) form
    return val;
}

double itr (double x0, double err)
{
    double x=x0;
    int n=0; // to store number of iterations

    do{
        n++;
        x0=x;
        x = func(x);
        printf("iteration:%d\tx_n+1: %lf\t\tx_n: %lf\n",n,x,x0);
    } while (fabs(x-x0)>err);

    return x;
}

int main()
{
    double x,err;
    printf("Initial Approximation: ");
    scanf("%lf", &x);
    printf("Error: ");
    scanf("%lf", &err);

    printf("Root is %lf",itr(x,err));
}
