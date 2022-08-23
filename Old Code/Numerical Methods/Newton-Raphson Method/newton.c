/*
 This is a  program to test Newton-Raphson method.
Author: Sourish Mandal
Date: 11th Feb 2022
*/
#include <stdio.h>
#include <math.h>

double function (double x)
{
	double val = pow (x, 3) +x -1;
	return val;
}
double derivative(double x)
{
    double df = 3*x*x +1 ;
    return df;
}
double calculate (double x_0, double err)
{
	double x;
	int n = 0;

	do
	{
		n += 1; // increase number of iterations

		x = x_0 - function (x_0)/derivative(x_0);
		printf("Iteration %d:\tf(root): %lf\troot: %lf\t\n", n, function(x),x );

		if (fabs(function(x)) == 0  )
		{
			return x;
		}

        x_0=x;

	}
	while (fabs(function(x)) > err);

	return x;
}
int main()
{
    printf("Initial guess: ");  
    double x_0;
    scanf("%lf", &x_0);

    printf("Error tolerance: ");
    double error;
    scanf("%lf", &error);

    double root = calculate(x_0, error);

    printf("\nRoot is %lf", root);

}

