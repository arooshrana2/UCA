#include<stdio.h>
typedef struct stack{
    int top;
    char *arr;
}st;
st s;
void push( char ch ) {
    s.arr[++s.top] = ch;
}

char pop () {
    return s.arr[s.top--];
}

void createStack (int len) {
    s.arr = (char*) malloc (sizeof(char)*len);
    s.top = -1;
}

void inputValues ( char *str ) {
    int i = 0;
    while ( str[i] != '\0' ) {
        push ( str[i++] );
    }


}

void stackRev( char *str ) {
    int i = 0;
    while ( s.top >= 0 ) {
        str[i++] = pop();
    }
    printf ("\n");
}

int main() {
    char *str = (char*) malloc (sizeof(char)*20);
    scanf ( "%[^\n]s", str );
    createStack (strlen(str));
    inputValues (str);
    stackRev( str );
    printf ( "%s\n", str );
return 0;
}
