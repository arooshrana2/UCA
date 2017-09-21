#include<stdio.h>
#include<string.h>
char arr[64] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/"};
void toChar ( int mul ) {
    printf ( "%c", arr[mul] );
}
void encode( char* str ) {
    int len = strlen ( str );
    int i, j, n = 0, no, k = 0;
    int l = len, num = 0;
    while( len*8 % 6 ) {
        len++;
    }
    while( k < len ) {
            int m=0;
            n=0;
        if( l==3 ) {
            for( i=k; i < (k+l); i++ ) {
                n = (n<<8) ^ str[i];
            }
            no = l*8;
            while( no % 6 ) {
                n <<= 1;
                no++;
            }
            j = no/6;
        }
        else if ( l < 3 ) {
            m = strlen ( str );
            j = m%3;
            if( j == 1 ) {
                j = 2;
                num = 2;
                n = str[k];
                n <<= 4;
                m = 2;
            }
            else {
                j = 3;
                num = 1;
                for( i = k; i < k+2; i++ ) {
                    n = ( n << 8 ) ^ str[i];
                }
                n <<= 2; m =  1;
            }
        }
        else {
            for( i = k; i < ( k+3 ); i++ ) {
                n=(n<<8)^str[i];
            }
            j=4;
        }
        while ( j ) {
            toChar ( ( n >> ( (j-1) * 6 ) ) & 63 );
            j--;
        }
        if( m != 0 ) {
            for( i=0; i<m; i++ )
                printf ( "=" );
        }
        l -= 3; k += 3;
    }
}
int main() {
    char *str = malloc ( 64 * sizeof(char) );
    scanf ( "%[^\n]s", str );
    printf ( "\n\n" );
    printf ( "Scanned string is: %s \n", str );
    printf ( "\n\n" );
    encode ( str );
    printf( "\n\n" );
return 0;
}
