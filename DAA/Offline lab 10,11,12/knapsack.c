/* This is a program to solve the knapsack problem by greedy algorithm approach. */
/* @Author: Sourish Mandal */
/* @Date: 20-02-2022 */

#include <stdio.h>

void sort_arrays(double *p,double *w,int n)
{
    double temp=0.0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n-1; j++)
        {
            if (p[j]/w[j] < p[j+1]/w[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
}

void knapsack(double *x,double *w, int m, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        x[i]=0.0;
    }

    for (i=0; i<n; i++)
    {
        if (w[i] > m)
            break;
        x[i]=1.0;
        m=m-w[i];
    }
    if (i <= n)
        x[i]=m/w[i];
}
int main()
{
    printf("Enter the number of items in array: ");
    int n; scanf("%d",&n);
    printf("Enter maximum weight m: ");
    int m; scanf("%d",&m);
    
    double price[n],weight[n],x[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter price of item %d: ",i+1);
        scanf("%lf",&price[i]);
        printf("Enter weight of item %d: ",i+1);
        scanf("%lf",&weight[i]);
    }
    sort_arrays(price,weight,n);
    for (int i=0; i<n; i++)
    {
        printf("%lf\t%lf     %lf\n",price[i],weight[i],price[i]/weight[i]);
    }
    knapsack(x, weight, m, n);
     
    for (int i=0; i<n; i++)
    {
        printf("Item %d has weight %lf, price %lf and should be in %lf portion.\n", i, weight[i], price[i], x[i]);
    }
        

}


