#include <stdio.h>
#include <stdlib.h> //for system calls
#define maximum 5
void insert();
void delete();
void display();
//these are three functions required for Queue
int front = 0, rear = -1, arr[maximum];
int main()
{
    system("cls");
    int n;
    printf("\n\t\t\t1. Insert \n\t\t\t2. Delete \n\t\t\t3. Display \n\t\t\t4. Exit");

    for(;;)
    {
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
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

void insert()
{
    int v;

    if (rear == maximum - 1)
    { printf("\n\t\t\tQueue Overflow\n"); }
    else
    {
        printf("\n\t\t\tEnter value: ");
        scanf("%d", &v);
        rear++;
        arr[rear] = v;
    }
}

void delete()
{
    if (front > rear)
    { printf("\n\t\t\tQueue Underflow\n"); }
    else
    {
        printf("\n\t\t\t%d is deleted", arr[front]);
        front++;
    }
}

void display()
{
    int i;

    if (front > rear)
    { printf("\n\t\t\tQueue Empty\n"); }
    else
    {
        for(i = front; i <= rear; i++)
        { printf("\t%d", arr[i]); }
    }
}
