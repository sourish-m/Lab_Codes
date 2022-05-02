/* This is a program to test the gauss elimination method for solving system of linear equations. */
#include <stdio.h>
/* #include <math.h> */
/* #include <stdlib.h> */

void matrix_solver( int n,double matrix[n][n+1],double x[10])
{
    double k,p;
   for (int i=0; i<n-1; i++)
   {
       k=matrix[i][i]; 

       for (int j=0; j<n+1; j++)
       {
           matrix[i][j] /= k;
       }
       for (int l=i+1; l<n; l++)
       {
           p=matrix[l][i];
           for (int j=0; j<n+1; j++)
           {
               matrix[l][j] -= matrix[i][j]*p;
           }
       }
       /* printf("\nfor row %d, The matrix is:\n",i); */
       /* for (int i = 0; i < n; i++) */ 
       /* { */
       /*     for (int j=0; j<(n+1); j++) */ 
       /*     { */
       /*         printf(" %0.2lf ",matrix[i][j]); */
       /*     } */
       /*     printf("\n"); */
       /* } */
            
    }

   for(int i = n-1; i>=0; i--)
   {
       x[i] = matrix[i][n];
       for (int j=i+1; j<n; j++)
       {
           x[i] -= matrix[i][j]*x[j];
       }

       x[i] = x[i]/matrix[i][i];

   }
}

int main()
{
    /* FILE *f; f=fopen(".\\input.txt","r"); */
    printf("Enter the order of the matrix:\n");
    int n;
    scanf("%d",&n);
    printf("Enter the augmented matrix:\n");
    double matrix[n][n+1], x[10];
    for (int i = 0; i < n; i++) 
    {
        printf("Enter row %d:\n",i+1);
       for (int j=0; j<(n+1); j++) 
       {
           scanf("%lf",&matrix[i][j]);
       }
    }
    printf("The input matrix is:\n");
    for (int i = 0; i < n; i++) 
    {
       for (int j=0; j<(n+1); j++) 
       {
           printf(" %0.2lf ",matrix[i][j]);
       }
       printf("\n");
    }
    
    matrix_solver(n,matrix,x);
    printf("\nThe solution is: \n");
    for(int i=0; i<=n-1; i++)
    {
		printf("x[%d] = %0.3f\n", i+1, x[i]);
        
    }
    return 0;

}


