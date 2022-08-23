#include <stdio.h>
int main()
{
    int i = 2, sum = 0;
    printf("\nThe series of integers is as follows\n");

    for (i; i < 150; i += 3)
    {
        if(i % 5 == 0)
        { sum += i; }

        printf("\t%d", i);
    }

    printf("\nThe sum of integers divisible by 5 is %d\n", sum);
    return 0;
}
