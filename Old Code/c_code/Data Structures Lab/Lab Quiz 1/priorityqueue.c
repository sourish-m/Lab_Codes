#include <stdio.h>
#include <stdlib.h> // for exit() function in Switch-Case

#define MAX 5

void create();
void insert(int);
void delete(int);
void find_priority(int);
void display();

int arr[MAX];
int f, r;

void main()
{
    int n, ch;
    printf("\n1.Insert Value 2.Delete Value 3.Display Queue 4.Exit Program\n");
    create();

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted : ");
            scanf("%d", &n);
            insert(n);
            break;

        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d", &n);
            delete(n);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}

/* Function to create an empty priority queue */
void create()
{
    f = r = -1;
}

/* Function to insert value into priority queue */
void insert(int data)
{
    if (r >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }

    if ((f == -1) && (r == -1))
    {
        f++;
        r++;
        arr[r] = data;
        return;
    }
    else
    { find_priority(data); }

    r++;
}

/* Function to check priority and place element */
void find_priority(int data)
{
    int i, j;

    for (i = 0; i <= r; i++)
    {
        if (data >= arr[i])
        {
            for (j = r + 1; j > i; j--)
            { arr[j] = arr[j - 1]; }

            arr[i] = data;
            return;
        }
    }

    arr[i] = data;
}

/* Function to delete an element from queue */
void delete(int data)
{
    int i;

    if ((f == -1) && (r == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }

    for (i = 0; i <= r; i++)
    {
        if (data == arr[i])
        {
            for (; i < r; i++)
            { arr[i] = arr[i + 1]; }

            arr[i] = -99;
            r--;

            if (r == -1)
            { f = -1; }

            return;
        }
    }

    printf("\n%d not found in queue to delete", data);
}

/* Function to display queue elements */
void display()
{
    if ((f == -1) && (r == -1))
    {
        printf("\nQueue is empty");
        return;
    }

    for (; f <= r; f++)
    { printf(" %d ", arr[f]); }

    f = 0;
}
