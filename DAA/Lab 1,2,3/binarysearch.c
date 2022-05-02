#include <stdio.h>

int binarysearch ( int array[], int num, int n)
{
    int high, mid, low;
    low = array[0]; high = array[n];
    do
    {
        mid = (low + high) /2;
        if (num == array[mid])
            return mid;
        else if (num < array[mid])
            high = mid - 1;
        else low = mid + 1;
    } while (low < high);
}

int main()
{
    printf("Enter number of elements in array ");
    int n;
    scanf("%d", &n);
    printf("%d\n",n);
    int array[n];
    for (int i=0; i<n; i++)
    {
        printf("Array element %d is: ",i);
        scanf("%d", &array[i]);
    }
    printf("Enter element to search in array: ");    
    int search_element;
    scanf("%d", &search_element);
    int result= -1; result = binarysearch ( array, search_element, n);
    if (result >=0)
        printf("Element in present in array in position %d",result);
    
}
