#include <stdio.h>
int facto (int n)
{
    if (n != 1)
    {
        n = n * facto(n - 1);
        return n;
    }
    else
    { return 1; }
}
int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    printf("The Factorial of the entered number is\n%d", facto(n));
    return 0;
}
