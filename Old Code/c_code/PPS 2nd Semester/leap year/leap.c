#include <stdio.h>
int leapcheck(int);
int main()
{
    int year1 = 0, year2 = 0, val;
    printf("Enter any year\n");
    scanf("%d", &year1);
    //Enter input from user
    val = leapcheck(year1);

    if (val == 0)
    { printf("\nThe entered year is a leap year.\n"); }
    else if (val == 1)
    { printf("\nThe entered year is not a leap year.\n"); }

    printf("\nTo find leap year in a range, enter first year\n");
    scanf("%d", &year1); //Enter first year of range
    printf("\nEnter second year\n");
    scanf("%d", &year2); //Enter last year of range

    if (year2 < year1)
    { printf("\nfinal year cannot be earlier than initial year\n"); }

    for (int i = year1; i <= year2; i++)
    {
        if (leapcheck(i) == 0)
        { printf("\n%d is a leap year\n", i); }
    }   //code to print leap years in range

    return 0;
}

int leapcheck(int year)
{
    if (year % 4 != 0)
    { return 1; }
    else if (year % 100 != 0)
    { return 0; }
    else if (year % 400 != 0)
    { return 1; }
    else { return 0; }

    //code to check leap year
}
