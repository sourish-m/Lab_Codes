#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

void create();
void display( struct node *);
void countNodes();


struct node *h = NULL;

int main()
{
    int n;
    printf("\n\t1. Create\n\t2. Display\n\t3. Count Nodes\n\t4. Exit the program");
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
            countNodes();
            break;

        case 4:
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


void countNodes()
{
    struct node* temp = h;
    int i = 0;

    while(temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    printf("The Number of Nodes is %d\n", i);
}

