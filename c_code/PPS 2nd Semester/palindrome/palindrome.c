#include <stdio.h>
int main()
{
    printf("\nEnter a number to check whether palindrome or not\n");
    int n = 0;
    scanf("%d", &n);
    //Input the number
    int n1 = n, n2 = 0;

    do
    {
        n2 = n2 * 10 + (n % 10);
        n /= 10;
    }
    while (n > 0); //reverse the number and store it in n2

    if (n1 == n2)
    { printf("The entered number is a palindrome\n"); }
    else { printf("The entered number is not a palindrome\n"); }

    return 0;
}
