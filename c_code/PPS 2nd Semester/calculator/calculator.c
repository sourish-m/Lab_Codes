#include <stdio.h>
int main()
{
    printf("This program functions as a simple calculator\nFor addition enter +\nFor subtraction enter -\nFor multiplication enter *\nFor division enter /\n");
    char c;
    scanf("%s", &c);
    printf("Enter the two operands a and b\n");
    int a, b;
    scanf("%d\n%d", &a, &b);

    switch(c)
    {
    case '+':
        printf("a+b= %d\n", (a + b)); break;

    case '-':
        printf("a-b= %d\n", (a - b)); break;

    case '*':
        printf("a*b= %d\n", (a * b)); break;

    case '/':
        printf("a/b= %d\n", (a / b)); break;

    default:
        printf("Operator not recognized\n");
    }

    return 0;
}
