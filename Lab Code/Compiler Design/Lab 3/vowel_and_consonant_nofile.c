// program to check words starting with vowel and ending
// with consonant, from multi-line user input
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_vowel (char c)
{
	c = tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	else
		return 0;
}
int main()
{
	char s[100], *word;
	int line = 1;
	printf("Enter sentences:\n");
	while(scanf_s("%[^\n]%*c", s) == 1)
	{
		word = strtok (s, " "); // break word into tokens
		printf ("\nWords starting with vowel and ending with consonant are...\n");
		while (word != NULL)
		{
			if (check_vowel(word[0]) == 1 && check_vowel(word[strlen(word) - 1]) == 0)
			{
				for (int k = 0; k < strlen(word); k++)
					printf("%c", word[k]);
				printf("----> at line: %d\n", line);
			}
			word = strtok (NULL, " ");
		}
		printf("\n");
		line++;

	}
}
