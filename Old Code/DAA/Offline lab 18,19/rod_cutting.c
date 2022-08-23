#include <stdio.h>
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
} 
int rodCut(int price[], int n)
{
    int T[n + 1];
 
    for (int i = 0; i <= n; i++) {
        T[i] = 0;
    }
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++) {
            T[i] = max(T[i], price[j - 1] + T[i - j]);
        }
    }
 
    return T[n];
}
 
int main()
{
    int n ;
    printf("Enter the total length of the rod: ");
    scanf("%d",&n);
    int price[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter price of piece %d: ", i+1);
        scanf("%d", &price[i]);
    }
    printf("\nTotal profit is: %d ", rodCut(price, n));
 
 
    return 0;
}
