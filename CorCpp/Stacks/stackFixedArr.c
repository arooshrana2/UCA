#include<stdio.h>
int size =5;

struct stack {
   int a[5];
   int top; 
};
typedef struct stack Stack;
Stack tt;

void push ( int i ) {
   if (tt.top == 4 ) {
       printf ( " Overflow of size!\n" );
       return;
   }
   tt.a[++tt.top] = i;
   printf ("\nInserted\n");
}

int pop () {
   if ( tt.top == -1 ) {
      printf ( "Underflow of size!\n" );
      return 0;
   }
  return (tt.a[tt.top--]);
}

int main () {
tt.top = -1; 
   push(1);
   push(1);
   push(1);
   push(1);
   push(1);
   push(1);


   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );
   printf ( "%d ", pop() );


return 0;
}
