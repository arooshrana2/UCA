#include<stdio.h>
#include<string.h>
struct stack {
    char arr[10];
    int j;
};

typedef struct stack nn;
nn S;

void push ( char c) {
   S.arr[++S.j] = c;
}
char pop () {
    char c = S.arr[S.j--];
return c;
}

int isBal ( char *p, int n){
    if (n%2 != 0)
        return -1;
    else if ( p[n-1] == '{' || p[n-1] == '[' || p[n-1] == '(' )
        return 0;
    int i;
    char c;
    for ( i=0; i<n; i++ ) {
        if ( p[i] == '{' || p[i] == '[' || p[i] == '(' )
        {   
            push(p[i]);
            //printf ("if part %c\n", p[i] );    
        }
        else {
            c = pop();
           // printf ( "else part %c\n", c );
            if (c == '{' && p[i] != '}' )
                return 0;
            else if ( c== '[' && p[i] != ']' )
                return 0;
            else if ( c=='(' && p[i] != ')') 
                return 0;
        }
    }
    return 1;
}

int main() {
S.j = -1;
char *ptr = (char*) malloc ( 10*sizeof(char) );
scanf ("%s", ptr);
int n = strlen(ptr);
printf ( "%d\n", isBal(ptr,n) );
return 0;
}
