#include <stdio.h>
void primecheck(int);
void fibonacci(int);
int main()
{
    int n = 0, choice = 0;
    printf("\nEnter an integer\n");
    scanf("%d", &n);
    printf("\nPress 1 for checking prime number and press 2 for checking fibonacci number\n");
    scanf("%d", &choice);

    //input of integer and choice

    if (choice == 1)
    { primecheck(n); }
    else if (choice == 2)
    { fibonacci(n); }
    else { printf("\nWrong choice entered"); }

    return 0;
}

void primecheck(int n)
{
    int c = 0;

    if (n == 0 || n == 1)
    {
        printf("\nNeither prime nor composite.\n");
        return;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        { c++; }
    }

    if (c == 0)
    { printf("\nThe entered number is a Prime.\n"); }
    else { printf("\nThe entered number is not a Prime.\n"); }
}

void fibonacci(int n)
{
    int a = 1, b = 1, c = 0, d = 0;

    while(b <= n)
    {
        if (n == b)
        { c++; }

        d = b;
        b = b + a;
        a = d;
    }

    if (c == 0)
    { printf("\n Not a Fibonacci number.\n"); }
    else { printf("\nFibonacci number.\n"); }
}
