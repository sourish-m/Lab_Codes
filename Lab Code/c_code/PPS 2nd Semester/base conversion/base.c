#include <stdio.h>
char conv(int num)
{
    if (num >= 0 && num <= 9)
    { return (char)(num + '0'); }
    else
    { return (char)(num - 10 + 'A'); }
}
int main()
{
    int n, base, i = 0; int arr[10];
    printf("\nEnter a decimal number\n");
    scanf("%d", &n);
    printf("Enter the base you wish to convert to\n");
    scanf("%d", &base);

    do
    {
        arr[i] = n % base;
        n = n / base;
        i++; 
    }
    while (n > 0);


    for (int j=i-1; j>=0; j--)
    {
        printf("%c", conv(arr[j])); 
    }

    printf("\n");
    return 0;
}
