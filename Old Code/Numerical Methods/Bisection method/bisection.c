/*
 This is a  program to test bisection method of solving non-Linear Equations.
Author: Sourish Mandal
Date: 19/Jan/2022
*/
#include <stdio.h>
#include <math.h>

double function (double x)
{
     return pow(x,3)-5*x+3;
}
double calculate (double a, double b, double err)
{
    double mid_val;
    int n = 0;

    do
    {
        n += 1; // increase number of iterations

        mid_val = function((a + b) / 2);
        printf("Iteration %d:\tf(root):%lf\ta:%lf\tb:%lf\n", n, mid_val, a, b);

        if (fabs(mid_val) == 0  )
        {
            return (a + b) / 2;
        }
        else if (mid_val * function(a) < 0)
            b = (a + b) / 2;
        else a = (a + b) / 2;

    }
    while (fabs(b - a) > err);

    return (a + b) / 2;
}
int main()
{
    double a, b;

    do
    {
        printf("\nEnter a and b:\n");
        scanf("%lf\n%lf", &a, &b);

        printf("f(a) is: %lf\nf(b) is: %lf\n", function(a), function(b));

        if ( !(function(a) * function(b) < 0))
            printf("Initial approximation incorrect");

    }
    while ( !(function(a) * function(b) < 0) );

    printf("Enter the maximum error allowed: ");
    double error;
    scanf("%lf", &error);

    double root = calculate(a, b, error);

    printf("\nThe root of the given equation is %lf", root);

}
