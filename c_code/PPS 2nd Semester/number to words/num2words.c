#include <stdio.h>
int main()
{
    char *arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};	//array that stores words corresponding to digits
    int num, c, num2 = 0;
    printf("Enter a number to convert to words\n");
    scanf("%d", &num);
    printf("The number in words is\n");

    do
    {
        num2 = num2 * 10 + (num % 10);
        num /= 10;
    }
    while(num > 0);

    do
    {
        c = num2 % 10;
        printf("%s\t", arr[c]);
        num2 /= 10;
    }
    while(num2 > 0);

    printf("\n");
    return 0;
}

