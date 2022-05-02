#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node* next;
};

void insert(struct Node** poly)
{
    int coeff, exp, cont;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    *poly = temp;

    do
    {
        printf("\n Coeffecient: ");
        scanf("%d", &coeff);
        printf("\n Exponent: ");
        scanf("%d", &exp);
        temp->coeff = coeff;
        temp->pow = exp;
        temp-> next = NULL;
        printf("\nContinue? 1 for yes and 0 for no: ");
        scanf("%d", &cont);

        if(cont)
        {
            temp->next = (struct Node*)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    while(cont);
}

void display(struct Node* poly)
{
    printf("\nPolynomial expression is: ");

    while(poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;

        if(poly != NULL)
        { printf("+"); }
    }
}

void add(struct Node** result, struct Node* first, struct Node* second)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    *result = temp;

    while(first && second)
    {
        if(first->pow > second->pow)
        {
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        }
        else if(first->pow < second->pow)
        {
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->next;
        }
        else
        {
            temp->coeff = first->coeff + second->coeff;
            temp->pow = first->pow;
            first = first->next;
            second = second->next;
        }

        if(first && second)
        {
            temp->next = (struct Node*)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    }

    while(first || second)
    {
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->next = NULL;

        if(first)
        {
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        }
        else if(second)
        {
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->next;
        }
    }
}

int main()
{
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* result = NULL;
    printf("\nEnter the corresponding data:-\n");
    printf("\nFirst polynomial:\n");
    insert(&first);
    display(first);
    printf("\nSecond polynomial:\n");
    insert(&second);
    display(second);
    add(&result, first, second);
    printf("\nCalculating the result.....\n");
    display(result);
    return 0;
}
