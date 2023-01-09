/*
 This is a  program to test bisection method , this also determines a and b by itself.
Author: Sourish Mandal
Date: 19/Jan/2022
*/
#include <stdio.h>
#include <math.h>

double function (double x)
{
	double val = pow(x, 3) + 4 * x * 2 - 27 ;
	return val;
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
	while (fabs((b - a)) > err);

	return (a + b) / 2;
}

double find_b()
{
	double b;
	int i;
	for (i = 0;; i++)
	{
		if (function(i) > 0)
		{
			b = i;
			return b;
		}
	}
}
double find_a()
{
	double a;
	int j;

	for (j = 0;; j--)
	{
		if (function(j) < 0)
		{
			a = j;
			return a;
		}
	}
}
int main()
{
	double a, b;
	a = find_a();
	b = find_b();

	printf("a is:%lf and b is:%lf\n", a, b);
	printf("Enter the maximum error allowed: ");
	double error;
	scanf("%lf", &error);

	double root = calculate(a, b, error);

	printf("\nThe root of the given equation is %lf", root);

}
