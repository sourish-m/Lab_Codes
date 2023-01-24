
#include <stdio.h>
#include <string.h>
int main()
{
	FILE *f;
	f = fopen ( "data.txt", "r" );
	char ch[10];
	int i = 0;

	while ( fscanf_s ( f, "%s", ch) == 1 )
	{
		i++;
		if (strcmp(ch, "study") == 0)
			printf("\nPosition of the word 'study' is: %d", i);
		else if (strcmp(ch, "experience") == 0)
			printf("\nPosition of the word 'experience' is: %d", i);
	}
}
