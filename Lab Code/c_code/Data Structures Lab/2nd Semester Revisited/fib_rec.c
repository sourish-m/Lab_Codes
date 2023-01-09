#include <stdio.h>

int fibbonacci(int n)
{
    if(n == 0)
    { return 0; }
    else if(n == 1)
    { return 1; }
    else
    { return (fibbonacci(n - 1) + fibbonacci(n - 2)); }
}

int main()
{
    int n;
    printf("Enter number of terms \n");
    scanf("%d", &n);
    printf("The Fibonacci Sequence till the entered term is\n");

    for(int i = 0; i < n; i++)
    { printf("%d ", fibbonacci(i)); }

    return 0;
}
