// program to access any text file from desktop
#include <stdio.h>

int main()
{
	FILE *f;
	f= fopen("data.txt","r");
	char ch[10];
	
	while( fgets(ch, 10, f) != NULL)
	{
		printf("%s", ch);
	}
	
}
