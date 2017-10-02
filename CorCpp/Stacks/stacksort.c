#include<stdio.h>

typedef struct st{
    int *arr;
    int top;
}nn;
nn obj;

void createStack () {
    obj.top = -1;
    obj.arr = (nn*) malloc (sizeof(int)*15);
}

void push ( int n ) {
    obj.arr[++obj.top] = n;
}

void emptyStack () {
    if ( obj.top == -1 )
        return;
    int temp = obj.arr[obj.top--];
    emptyStack ();
    sort(temp);
}

void sort ( int t ) {
    if ( obj.top == -1 || t > obj.arr[obj.top] ) 
        obj.arr[++obj.top] = t;
    else
    {
        int temp = obj.arr[obj.top--];
        sort (t);
        push (temp);
    }   
}

void print () {
    printf ( "%d\n", obj.arr[obj.top--]);
}
int main() {
    createStack();
    push(5);
    push(3);
    push(8);
    push(1);
    push(10);
    push(9);
    push(14);
    push(2);
    printf ( "top = %d\n", obj.top );
    emptyStack();
    print();
    print();
    print();
    print();
    print();
    print();
    print();
    print();

return 0;
}
