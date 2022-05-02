#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *prev;
    struct node *next;
};

struct node *h = NULL;
void delet (struct node *ls)
{
    int pos, i;
    struct node *temp;
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if ( pos == 1)
    {
        h = h->next;
        free(ls);
        h->prev = NULL;
    }
    else
    {
        for (i = 1; i < pos - 2; i++)
        { ls = ls->next; }

        temp = ls->next;
        ls->next = ls->next->next;
        free(temp);
        ls->next->prev = ls;
    }
}

void create()
{
    int n;
    char ch;
    struct node *ls;

    do
    {
        printf("\nEnter value: ");
        scanf("%d", &n);

        if (h == NULL)
        {
            h = (struct node *)malloc(sizeof(struct node));
            h->val = n;
            h->prev = NULL;
            h->next = NULL;
        }
        else
        {
            ls = h;

            while (ls->next != NULL)
            { ls = ls->next; }

            ls->next = (struct node*)malloc(sizeof(struct node ));
            ls->next->val = n;
            ls->next->prev = ls;
            ls->next->next = NULL;
        }

        printf("\nWant to continue...(y/n)");
        fflush(stdin);
        scanf("%c", &ch);
    }
    while (ch == 'y');
}

void insert (struct node *ls)
{
    int i, v, pos;
    struct node *temp;
    printf("\n Enter value and position: ");
    scanf("%d %d", &v, &pos);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = v;

    if (pos == 1)
    {
        temp->next = h;
        h->prev = temp;
        h = temp;
        temp->prev = NULL;
    }
    else
    {
        for (i = 1; i <= pos - 2; i++)
        { ls = ls->next; }

        temp->next = ls->next;
        ls->next = temp;
        temp->next->prev = temp;
        temp->prev = ls;
    }
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


int main()
{
    int n;
    printf("\n\t1. Create\n\t2. Display\n\t3. Insert\n\t4. Delete\n\t5. Exit the program");
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
            delet(h);
            break;

        case 5:
            exit(0); // exits the program
        }
    }
} // closing main() function
