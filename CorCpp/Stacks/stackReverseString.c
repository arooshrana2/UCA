#include<stdio.h>

typedef struct string{
    char *str;
    int top;
}strr;
strr st;
void push( char ch ) {
    st.str[++st.top] = ch;
}
char pop() {
    return st.str[st.top--];
}
void reverse ( char *s ) {
    int i = 0, len = strlen(s);
    for ( ; i<len; i++ ) {
        push(s[i]);
    }
    for ( i=0; i<len; i++ ) {
        s[i] = pop();
    }
    s[i] = '\0';
}

void print ( char *s ) {
    printf ( "%s\n", s );
}

int main() {
    st.top = -1;
    char *s = (char*) malloc ( sizeof(char)*20 );
    st.str = (char*) malloc (sizeof(char)*20);
    scanf ( "%s", s );
    reverse (s);
    print (s);
return 0;
}
