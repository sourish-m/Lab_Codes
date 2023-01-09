#include <stdio.h>
#include <stdlib.h> //for system calls
#define max 5
void insertbeg();
void insertend();
void deletebeg();
void delete_end();
void display();
int f = 0, r = -1, a[max], count = 0;

void insertbeg()
{
    int i = 0;

    if (count == max)
    { printf("Queue Overflow\n"); }
    else
    {
        int v;
        printf("\n\t\t\tEnter value: ");
        scanf("%d", &v);

        if (r >= f)
        {
            for (i = r; i >= f; i--)
            {
                if (i == max - 1)
                { a[0] = a[i]; }
                else
                { a[i + 1] = a[i]; }
            }
        }

        if (r < f)
        {
            for (i = r; i >= 0; i--)
            { a[i + 1] = a[i]; }

            a[0] = a[max - 1];

            for (i = max - 1; i > f; i--)
            { a[i] = a[i - 1]; }
        }

        a[f] = v;
        r++;

        if (r > max - 1)
        { r = 0; }

        count++;
    }
}
void insertend()
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

void deletebeg()
{
    if (count == 0)
    { printf("Queue Underflow\n"); }
    else
    {
        printf("\t\t\t%d is deleted\n", a[f]);
        f++;

        if (f == max)
        { f = 0; }

        count--;
    }
}

void delete_end()
{
    if (count == 0)
    { printf("Stack Underflow\n"); }
    else
    {
        printf("\t\t\t%d is deleted\n", a[r]);
        r--;

        if (r < 0)
        { r = max - 1; }

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
            printf("\n\t\t\t");

            for (int i = f; i <= r; i++)
            { printf("%d\t", a[i]); }
        }

        if (r < f)
        {
            printf("\n\t\t\t");

            for (int i = f; i <= max - 1; i++)
            { printf("%d\t", a[i]); }

            for (int i = 0; i <= r; i++)
            { printf("%d\t", a[i]); }
        }
    }
}

int main()
{
    system("cls");
    int n;
    printf("\n1.Insert from Beginning\n2.Insert at End\n3.Delete from Beginning\n4.Delete from End\n5.Display\n6.Exit\n");

    for(;;)
    {
        printf("\n\t\t\t\tEnter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            insertbeg();
            break;

        case 2:
            insertend();
            break;

        case 3:
            deletebeg();
            break;

        case 4:
            delete_end();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("\n\t\t\tWrong choice Entered\n");
        }
    }

    return 0;
}
