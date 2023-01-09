#include <stdio.h>
#include <stdlib.h> //for system calls
#define max 5
void insert();
void delete();
void display();
int f = 0, r = -1, a[max], count = 0;

void insert()
{
    if (count == max)
    { printf("Queue Overflow\n"); }
    else
    {
        int v;
        printf("\n\t\t\tEnter value: ");
        scanf("%d", &v);
        r++;

        if (r == max)
        { r = 0; }

        a[r] = v;
        count++;
    }
}

void delete()
{
    if (count == 0)
    { printf("Queue Underflow\n"); }
    else
    {
        printf("%d is deleted\n", a[f]);
        f++;

        if (f == max)
        { f = 0; }

        count--;
    }
}
void display()
{
    if (count == 0)
    { printf("Queue Empty\n"); }
    else
    {
        if (r >= f)
        {
            for (int i = f; i <= r; i++)
            { printf("%d\n", a[i]); }
        }

        if (r < f)
        {
            for (int i = f; i <= max - 1; i++)
            { printf("%d\n", a[i]); }

            for (int i = 0; i <= r; i++)
            { printf("%d\n", a[i]); }
        }
    }
}

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
