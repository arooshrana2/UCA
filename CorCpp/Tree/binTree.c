#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
   struct Node* left;
   struct Node* right;
};

struct Node* insert (struct Node *head, int data ) {   
	if ( head == NULL ) {
        struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if ( head->data > data ) {
        head->left = insert ( head->left, data );
    }
    if ( head->data < data ){
        head->right = insert ( head->right, data );
    }
return head;
}

void print ( struct Node *h ) {
   if(h == NULL){
	    return;
   }
	 if ( h != NULL ) {
       printf ( "%d->", h->data );
       if(h->left)
	         print ( h->left );
       if(h->right)
	         print ( h->right );
   }
}

int main() {
struct Node *h;
h = insert ( h, 1 );
h = insert ( h, 5 );
h = insert ( h, 9 );
h = insert ( h, 3 );
h = insert ( h, 6 );
h = insert ( h, 8 );
h = insert ( h, 10 );
h = insert ( h, 7 );
print (h);
return 0;
}
