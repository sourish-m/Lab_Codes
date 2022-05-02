#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *link;
};

struct node *head = NULL, *x, *y, *z;

void create();
void insert();
void delete();
void display();

void main()
{
    int ch;
    printf("\n1.create 2.insert 3.display 4.delete 5.exit\n");

    while (1)
    {
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            insert();
            break;

        case 3:
            display();
            break;

        case 4:
            delete();
            break;

        case 5:
            exit(0);
        }
    }
}

/*Function to create a new circular linked list*/
void create()
{
    char c;
    x = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the value: ");
    scanf("%d", &x->val);
    x->link = x;
    head = x;
    printf("\nContinue?(y/n)");
    fflush(stdin);
    scanf("%c", &c);

    do
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter the val: ");
        scanf("%d", &y->val);
        x->link = y;
        y->link = head;
        x = y;
        printf("\nContinue?(y/n)");
        fflush(stdin);
        scanf("%c", &c);
    }
    while (c == 'y');
}
void insert()
{
    struct node *ptr;
    int c = 1, pos, count = 1;
    y = (struct node*)malloc(sizeof(struct node));

    if (head == NULL)
    { printf("cannot enter an element at this place"); }

    printf("\n Enter the val: ");
    scanf("%d", &y->val);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    x = head;
    ptr = head;

    while (ptr->link != head)
    {
        count++;
        ptr = ptr->link;
    }

    count++;

    if (pos > count)
    {
        printf("OUT OF BOUND");
        return;
    }

    while (c < pos)
    {
        z = x;
        x = x->link;
        c++;
    }

    y->link = x;
    z->link = y;
}
/*Function to delete an element at any begining of the list*/

void delete()
{
    if (head == NULL)
    { printf("\n List is empty"); }
    else
    {
        x = head;
        y = head;

        while (x->link !=  head)
        { x = x->link; }

        head = y->link;
        x->link = head;
        free(y);
    }
}


/*Function to display the elements in the list*/

void display()
{
    if (head == NULL)
    { printf("\n List is empty"); }
    else
    {
        x = head;

        while (x->link !=  head)
        {
            printf("%d->", x->val);
            x = x->link;
        }

        printf("%d", x->val);
    }
}

