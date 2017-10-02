#include<stdio.h>
typedef struct stack{
    int top;
    int *arr;
}st;
st obj;
void push( int x ) {
    obj.arr[++obj.top] = x;
}

int isEmpty() {
    return ( (obj.top == -1) ? 0 : 1 );
}

int pop() {
    return (obj.arr[obj.top--]);
}

void NGE ( int *a ) {
    push(a[0]);
    int i, j;
    for ( i=1; i<5; i++ ) {
        int nxt = a[i];
        if ( isEmpty() != 0 ) {
            int ele = pop();
            //printf ( "%d\n", obj.top );
            while ( ele < nxt ) {
                printf ( "%d --> %d, top = %d\n", ele, nxt, obj.top );
                if ( isEmpty() == 0 ) {
                    break;
                }
                ele = pop();
            }
            if ( ele > nxt ) {
                push(ele);
            }
        }
        push(nxt);
    }
    while ( isEmpty() != 0 ) {
        printf ( "%d --> -1\n", pop() );
    }
}

int main() {
    obj.top = -1;
    obj.arr = (int*) malloc ( sizeof(int)*10 );
    int ar[] = { 5, 1, 4, 9, 2 };
    NGE( ar );
return 0;
}

