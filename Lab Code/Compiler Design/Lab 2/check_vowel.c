
#include <stdio.h>
#include <string.h>
int main() {
	FILE *f;
	f = fopen ( "data.txt", "r" );
	char ch[10];
	int n = 0;

	while ( fscanf ( f, "%s", ch ) == 1 ) {
		n = strlen(ch)-1;
		if (ch[0] == 'a'|| ch[0] == 'e'|| ch[0]== 'i' || ch[0] == 'o' || ch [0] == 'u') {
			if ( ch [n] == 'z' || ch [n] == 'x' || ch [n] == 'p' ) {
				printf("Word is %s\n", ch);
			}
		}
	}
}
