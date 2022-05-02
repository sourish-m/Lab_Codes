#include<stdio.h>

int main()
{
	double array[10][10], x[10], coeff;
	int i, j, k, n;
	printf("Enter number of equations: ");
	scanf("%d", &n);
	printf("Enter coefficients of Augmented Matrix:\n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n + 1; j++)
		{
			printf("array[%d][%d] = ", i, j);
			scanf("%lf", &array[i][j]);
		}
	}
    printf("The input matrix is:\n");
    for (int i = 1; i <= n; i++) 
    {
       for (int j=1; j<=(n+1); j++) 
       {
           printf(" %0.2lf ",array[i][j]);
       }
       printf("\n");
    }
	for(i = 1; i <= n; i++)
	{
		if(array[i][i] == 0.0)
		{
			printf("Mathematical Error!");
			return 1;
		}
		for(j = 1; j <= n; j++)
		{
			if(i != j)

			{
				coeff = array[j][i] / array[i][i];
				for(k = 1; k <= n + 1; k++)
				{
					array[j][k] = array[j][k] - coeff * array[i][k];
				}
			}
		}
	}
	for(i = 1; i <= n; i++)
	{
		x[i] = array[i][n + 1] / array[i][i];
	}
	printf("\nSolution:\n");
	for(i = 1; i <= n; i++)
	{
		printf("x[%d] = %0.3f\n", i, x[i]);
	}
	return 0;
}
