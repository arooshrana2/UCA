#include<stdio.h>
typedef struct twoStacks {
    int *arr;
    int top1, top2;
}ts;
ts obj;

void push1( int x ) {
    if ( obj.top1 < obj.top2-1 ) {
        obj.arr[++obj.top1] = x;
    }
    else
        printf("Stack Overflow\n");
}

void push2( int x ) {
    if ( obj.top1 < obj.top2-1 ) {
        obj.arr[--obj.top2] = x;
    }
    else
        printf("Stack Overflow\n");
}

void pop1 () {
    if ( obj.top1 >=0 ) {
        printf ( "pop ele stack2 = %d\n", obj.arr[obj.top1--]);
    }
    else
        printf ( "Stack Underflow\n" );
}

void pop2 () {
    if ( obj.top2 < 20 ) {
        printf ( "pop ele stack1 = %d\n", obj.arr[obj.top2++]);
    }
    else
        printf ( "Stack Underflow\n" );
}

void print () {
    int i=0;
    for ( i=0; i<=obj.top1; i++) {
        printf ( "%d\t", obj.arr[i] );
    }
    printf ( "\n\n" );
    for ( i=19; i>=obj.top2; i-- ) {
        printf ( "%d\t", obj.arr[i] );
    }
    printf ( "\n\n" );
}

int main() {
    obj.arr = (int*) malloc (sizeof(int)*20);
    obj.top1 = -1;
    obj.top2 = 20;
    push1(1);
    push2(4);
    push2(1);
    push1(13);
    push1(10);
    push1(11);
    push2(5);
    push1(9);
    pop1();
    pop2();
    print();
}
