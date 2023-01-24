// program to display only those words having a and b
#include <stdio.h>

int main()
{
    FILE *f;
    f = fopen ( "data.txt", "r" );
    char ch[10];
    int count_a = 0, count_b = 0;

    while ( fscanf ( f, "%s", ch ) == 1 )
    {
        count_a = 0;
        count_b = 0;
        for ( int i = 0; i < 10; i++ )
        {
            if ( ch[i] == 'a' )
                count_a = 1;
            if ( ch[i] == 'b' )
                count_b = 1;
        }
        if ( count_a == 1 && count_b == 1 )
        {
            printf ( "%s ", ch );
        }
    }

}
