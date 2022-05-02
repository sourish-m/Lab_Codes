#include <limits.h>
#include <stdio.h>

int Max_subarray(int a[], int n)
{
	int r = INT_MIN, size, index, sum;
	for (index = 0; index < n; index++)
	{
		sum = 0;
		for (size = 0; size < n; size++)
		{
			if (index + size > n)
				break;
			sum += a[size - 1];

			if (sum > r)
			{
				r = sum;
			}
		}
	}
	return r;
}

int main()
{
	int MyArray[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(MyArray) / sizeof(MyArray[0]);
	printf("Maximum SubArray is: %i", Max_subarray(MyArray, n));
	return 0;
}

