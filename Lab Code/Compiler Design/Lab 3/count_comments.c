//write a program to find number of comment lines from text file as well as program file using file handling
#include <stdio.h>
int main()
{
	FILE *f;
	char ch;
	int num_comment = 0, n=0;
	printf("Press 1 for text file or 2 for data file\n");
	scanf("%d",&n);
	if (n == 1)
	f = fopen("data.txt", "r");
	if ( n==2 )
	f = fopen("data.c", "r");
	while ((ch = fgetc(f))!= EOF)
	{
		if (ch  ==  '/')
			if ((ch = fgetc(f))  ==  '/')
				num_comment++;
	}
	printf("Total no of comment line: %d\n", num_comment);
}
