#include<stdio.h>
int res = 0;
struct stack {
    int top;
    int arr[20];   
};
typedef struct stack Stack;
Stack S;
void calc (char);
int pop() {
    return (S.arr[S.top--]);
}

void push( int c) {
    S.arr[++S.top] = c;
}

void mul () {
    res = pop() * pop();
    push (res);
}

void div () {
    int a = pop();
    res = ( pop() / a );
    push (res);
}

void add () {
    res = pop() + pop ();
    push (res);
}
void sub () {
    int a = pop();
    res = pop() - a;
    push (res);
}

void mod () {
    int a = pop();
    res = ( pop() % a );
    push (res);
}
void calc ( char c ) { 
    if ( c == '*' )
        mul();
    else if ( c == '-' )
        sub();
    else if ( c == '+' )
        add();
    else if ( c == '/' )
        div();
    else if ( c == '%' )
        mod();
    else {
        printf ( "Enter valid characters!!\n");
        return;
    }
}

int main() {
    S.top = -1;
    int num;
    char expr[20];
    char *exp = expr;
    printf ( "Enter the expression: " );
    scanf ( "%s", exp );
    while ( *exp != NULL ) {
        if ( isdigit ( *exp ) ) {//exp[i]>='0' || exp[i]<='9'
            num = *exp - 48;
            push(num);
        }
        else {
            calc ( *exp );
        }
        exp++;
    }
    printf ( "%d\n", res );
return 0;
}
