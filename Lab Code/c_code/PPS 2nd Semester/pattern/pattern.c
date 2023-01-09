#include <stdio.h>
int main()
{
    int i = 0, c = 11;

    for (i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= (4 - i); j++)
        { printf("\t"); }	//print spaces

        for (c = 11; c >= (12 - i); c--)
        { printf("%d\t", c); }	//print decreasing number triangle

        for (c = (13 - i); c < 12; c++)
        { printf("%d\t", c); }	//print increasing number triangle

        printf("\n");
    }

    return 0;
}

