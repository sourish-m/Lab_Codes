#include <stdio.h>
void bubblesort(int arr[], int l)
{
    int temp;

    for ( int i = 0; i < l; i++)
        for ( int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

int main()
{
    int n;
    printf("Enter an Array of size n\n");
    printf("Enter n\n");
    scanf("%d", &n);
    int arr[n];

    for ( int i = 0; i < n; i++)
    {
        printf("Enter next array element\n");
        scanf("%d", &arr[i]);
    }

    printf("The unsorted array is\n");

    for ( int i = 0; i < n ; i++)
    { printf("%d ", arr[i]); }

    bubblesort(arr, n);
    printf("\nThe sorted array is\n");

    for ( int i = 0; i < n ; i++)
    { printf("%d ", arr[i]); }

    return 0;
}

