//wap to implement single linked list with the following functions
//1. create
//2. display
//3. insert
//4. delete
//5. reverse
//6. sorting
//7. searching

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
// creates a linked list structure
// this type of structure is known as self-referential structure

void create();
void display( struct node *);
void insert( struct node *);
void delete_s( struct node *);// delete is a keyword in Turbo C so don't use it in assignments
void reverse();
void sort( struct node *);
void search( struct node *);

struct node *h = NULL;

int main()
{
    int n;
    printf("\n\t1. Create\n\t2. Display\n\t3. Insert\n\t4. Delete\n\t5. Reverse\n\t6. Sorting\n\t7. Searching\n\t8. Exit the program");
    // Display the choices

    for(;;)
    {
        // infinite loop for obtaining choices
        printf("\n--------Enter Your Choice\t");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            create();
            break;

        case 2:
            display(h);
            break;

        case 3:
            insert(h);
            break;

        case 4:
            delete_s(h);
            break;

        case 5:
            reverse(h);
            break;

        case 6:
            sort(h);
            break;

        case 7:
            search(h);
            break;

        case 8:
            exit(0); // exits the program
        }
    }
} // closing main() function
void create()
{
    int n;
    char ch;
    struct node *ls;

    do
    {
        printf("\nEnter value: ");
        scanf("%d", &n); // input value for variable n

        if (h == NULL)
        {
            h = (struct node *)malloc(sizeof(struct node));
            h->val = n;
            h->next = NULL;
        }// create new structure if not present
        else
        {
            ls = h;

            while (ls->next != NULL)
            { ls = ls->next; }

            // go to the last structure
            ls->next = (struct node*)malloc(sizeof(struct node));
            ls->next->val = n;
            ls->next->next = NULL; //assign entered value to a newly created structure at end of list
        }

        printf("\nWant to cont...(y/n)?");
        fflush(stdin);
        scanf("%c", &ch);
    }
    while(ch == 'y');
}

void display(struct node *ls)
{
    while(ls != NULL)
    {
        printf("%d -> ", ls->val);
        ls = ls->next;
    }

    printf("End\n");
}

void insert (struct node *ls)
{
    int i, v, pos;
    struct node *temp;
    printf("\nEnter value and position ");
    scanf("%d %d", &v, &pos);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = v;

    if (pos == 1)
    {
        temp->next = h;
        h = temp;
    }
    else
    {
        for (int i = 1; i <= pos - 2; i++)
        { ls = ls->next; }

        temp->next = ls->next;
        ls->next = temp;
    }
}


void delete_s(struct node *ls)
{
    int pos, i;
    struct node *temp;
    printf("\nEnter position");
    scanf("%d", &pos);

    if (pos == 1)
    {
        h = h->next;
        free(ls);
    }
    else
    {
        for (i = 1; i <= pos - 2; i++)
        { ls = ls->next; }

        temp = ls->next;
        ls->next = ls->next->next;
        free(temp);
    }
}
void reverse()
{
    struct node* current = h;
    struct node *prev = NULL, *after = NULL;

    while (current != NULL)
    {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }

    h = prev;
}
void sort( struct node *ls)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (ls == NULL)
    { return; }

    do
    {
        swapped = 0;
        ptr1 = ls;

        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            {
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }

        lptr = ptr1;
    }
    while (swapped);
}

void search( struct node *ls)
{
    int k, count = 1, f;
    printf("\nEnter Search Value: ");
    scanf( "%d", &k);

    while (ls != NULL)
    {
        if (ls->val == k)
        {
            printf("\nFound at position %d", count);
            f = 1;
        }

        count++;
        ls = ls->next;
    }

    if (f == 0)
    { printf("\nNot Found\n"); }
}


