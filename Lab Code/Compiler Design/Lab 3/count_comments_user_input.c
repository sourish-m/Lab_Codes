//write a program to find number of comment lines from text file as well as program file
//and without file handling
#include <stdio.h>
int main()
{
	FILE *f;
	char ch;
	int num_comment = 0;
	printf("Enter ")
	while ((ch = getc(f))!= EOF)
	{
		if (ch  ==  '/')
			if ((ch = getc(f))  ==  '/')
				num_comment++;
	}
	printf("Total no of comment line: %d\n", num_comment);
}
