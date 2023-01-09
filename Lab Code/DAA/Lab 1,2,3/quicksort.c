#include <stdio.h>
void printarray(int a[], int n)  {  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
void quicksort(int array[],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(array[i]<=array[pivot]&&i<last)
            i++;
         while(array[j]>array[pivot])
            j--;
         if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }

      temp=array[pivot];
      array[pivot]=array[j];
      array[j]=temp;
      quicksort(array,first,j-1);
      quicksort(array,j+1,last);

   }
}
int main()
{  
     int n;
    printf("Enter an Array of size n\n");
    printf("Enter n\n");
    scanf("%d",&n);

    int a[n];
    for ( int i=0; i<n; i++)
    {
        printf("Enter next array element\n");
        scanf("%d",&a[i]);
    };  
    n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting array elements are - \n");  
    printarray(a, n);  
    quicksort( a, 0, n-1); 
    printf("After sorting array elements are - \n");  
    printarray(a, n);  
    return 0;  
}  
