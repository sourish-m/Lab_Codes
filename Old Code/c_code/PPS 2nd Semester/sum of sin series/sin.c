#include <stdio.h>
int main()
{
    float n, result, product;
    printf("Enter the number you wish to find sin of\n");
    scanf("%f", &n);
    n = (3.14159265 * n) / 180; // convert degree to radians
    double factorial;
    int itr = 1, sign = 1, count = 0;

    do
    {
        product = 1.0; factorial = 1;

        for( int i = 1; i <= itr; i++)
        {
            product *= n;	// calculate x^n
            factorial *= i;	// calculate factorial
        }

        result += (sign) * product / factorial;
        sign *= -1;	//changes sign of magnitude added to result in each step
        itr += 2;		//keeps track of the current term in the series
        count++;	// to count total number of iterations
    }
    while((product / factorial) > 0.00001);

    printf("The value of sin x is %f\n", result);
    printf("The number of terms used to find the answer is %d\n", count);
    return 0;
}
