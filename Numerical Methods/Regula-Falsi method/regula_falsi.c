/*
 This is a  program to test Regula-Falsi method of solving non-Linear Equations.
Author: Sourish Mandal
Date: 19/Jan/2022
*/
#include <stdio.h>
#include <math.h>

double function (double x)
{
	double val = pow (x, 2) - 5 * x + 2;
	return val;
}
double calculate (double a, double b, double err)
{
	double x0;
	int n = 0;

	do
	{
		n += 1; // increase number of iterations

		x0 =  (a * function(b) - b * function (a) ) / ( function (b) - function (a) );
		printf("Iteration %d:\tf(root)= %lf\troot= %lf\t\ta= %lf\tb= %lf\n", n, function(x0),x0, a, b);

		if (fabs(function(x0)) == 0  ) 
		{
			return x0;
		}
		else if (function (x0) * function (a) < 0)
			b = x0;
		else a = x0;

	}
	while (fabs (function (x0)) > err);

	return x0;
}
int main()
{
	double a, b;
	int c = 0;

	do
	{
		printf("\nEnter the value of a and b:\n");
		scanf("%lf\n%lf", &a, &b);

		printf("The Value of f(x) at a is: %lf\nThe Value of f(x) at b is: %lf\n", function(a), function(b));

		if ( (function(a) * function(b) < 0))
			c = 1;
		else
		{
			printf("Initial approximation a and b are not correct. Please enter them again.");
			c = 0;
		}

	}
	while ( c == 0 );

	printf("Enter the maximum error allowed: ");
	double error;
	scanf("%lf", &error);

	double root = calculate(a, b, error);

	printf("\nThe root of the given equation is %lf", root);

}
