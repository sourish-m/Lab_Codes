#include <stdio.h>
int main()
{
    int a, b, c;
    printf("\nEnter three numbers\n");
    scanf("%d\n%d\n%d", &a, &b, &c);
    //Enter three numbers
    int grt = (a > b) ? (a > c) ? a : c : (b > c) ? b : c;	//Finds greatest number
    printf("\nGreatest number among the three, is %d\n", grt);
    return 0;
}


