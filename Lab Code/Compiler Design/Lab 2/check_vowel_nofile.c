// program to display word starting with vowel and ending with z or x or p
#include <stdio.h>
#include <string.h>
int main() {
	char ch[10];
	printf("Enter a string: \n");
	while ( scanf ( "%s", ch ) == 1 ) {
		if (ch[0] == 'a'|| ch[0] == 'e'|| ch[0]== 'i' || ch[0] == 'o' || ch [0] == 'u') {
			if ( ch [ strlen (ch) - 1] == 'z' || ch [ strlen (ch) - 1] == 'x' || ch [ strlen (ch) - 1] == 'p' ) {
				printf("Word is %s\n", ch);
			}
		}
	}
}
