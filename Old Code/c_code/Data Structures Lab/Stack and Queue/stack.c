#include <stdio.h>
#include <stdlib.h> //for system calls
#define maximum 5
void push();
void pop();
void display();
//these are three functions required for stack

int TOP = -1, arr[maximum];
int main()
{
    system("cls");
    int n;
    printf("\n\t\t\t1. Push \n\t\t\t2. Pop \n\t\t\t3. Display \n\t\t\t4. Exit");

    for(;;)
    {
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\n\t\t\tWrong choice Entered\n");
        }
    }

    return 0;
}// end of main function

void push()
{
    int v;

    if (TOP == maximum - 1)
    { printf("\n\t\t\tStack Overflow\n"); }
    else
    {
        printf("\n\t\t\tEnter value: ");
        scanf("%d", &v);
        TOP++;
        arr[TOP] = v;
    }
}

void pop()
{
    if (TOP == -1)
    { printf("\n\t\t\tStack Underflow\n"); }
    else
    {
        printf("\n\t\t\t%d is deleted", arr[TOP]);
        TOP--;
    }
}

void display()
{
    int i;

    if (TOP == -1)
    { printf("\n\t\t\tStack Empty\n"); }
    else
    {
        for(i = 0; i <= TOP; i++)
        { printf("\t%d", arr[i]); }
    }
}
