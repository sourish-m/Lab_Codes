#include <stdio.h>
int gcd (int, int);
int main()
{
    printf("Enter two numbers to find their GCD\n");
    int a, b;
    scanf("%d\n%d", &a, &b);
    printf("G.C.D of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}

int gcd(int n1, int n2)
{
    if (n2 != 0)
    { return gcd(n2, n1 % n2); }
    else
    { return n1; }
}
