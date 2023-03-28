#include <stdio.h>
#include <string.h>
#include <ctype.h>

isvowel(char c) {
	c = tolower(c);
	if (c == 'a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 0;
	else return 1;
}

int main() {
	int len = 0, j, flag;
	FILE *f = fopen ("data.txt", "r");
	char ch[10];
	while (fscanf(f,"%s", ch) == 1) {
		len = strlen(ch);
		if (len<5)
			continue;
		j = isvowel(ch[0]);

		for (int i = j; i < len; i=i+2) {
			if (j == 0) {
				if ( isvowel(ch[i]) == 0 && isvowel(ch[i+1]) == 1)
					flag = 1;
				else {
					flag = 0;
					break;
				}
			}
			if ( j == 1) {
				if ( isvowel(ch[i]) == 0 && isvowel(ch[i-1]) == 1)
					flag = 1;
				else {
					flag =0;
					break;
				}
			}
		}
		if (flag == 1) printf(" %s ", ch);
	}
}
