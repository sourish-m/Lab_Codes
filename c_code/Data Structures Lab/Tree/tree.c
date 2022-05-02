#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int num;
    struct tree *left;
    struct tree *right;
};

typedef struct tree node;

int main()
{
    node *insert (node*, int);
    void inorder (node*);
    void preorder (node*);
    void postorder (node*);
    node *root = NULL;
    int x;
    char ch = 'y';

    while (ch == 'y')
    {
        printf("Enter the value to insert::");
        scanf("%d", &x);
        root = insert (root, x);
        printf("\nNodes in inorder::");
        inorder(root);
        printf("\nNodes in preorder::");
        preorder(root);
        printf("\nNodes in postorder::");
        postorder(root);
        fflush(stdin);
        printf("\nContinue?(y/n):");
        scanf("%c", &ch);
    }
}
node *insert ( node *root, int x)
{
    if (root == NULL)
    {
        root = (node *) malloc(sizeof(node));
        root->num = x;
        root->left = root->right = NULL;
    }
    else if (root->num > x)
    { root->left = insert (root->left, x); }
    else if (root->num < x)
    { root->right = insert (root->right, x); }
    else
    { printf ("\nDuplicate"); }

    return root;
}


void inorder (node *root)
{
    if (root != NULL)
    {
        inorder (root->left);
        printf("%d ", root->num);
        inorder(root->right);
    }

    return;
}

void preorder (node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->num);
        preorder (root->left);
        preorder(root->right);
    }

    return;
}

void postorder (node *root)
{
    if (root != NULL)
    {
        postorder (root->left);
        postorder (root->right);
        printf("%d ", root->num);
    }

    return;
}
