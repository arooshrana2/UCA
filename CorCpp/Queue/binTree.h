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
        //printf ( "%d ", temp->data );
        head->left = insert ( head->left, data );
    }
    if ( head->data < data ){
       // printf ( "%d ", temp->data );
        head->right = insert ( head->right, data );
    }
return head;
}

void print ( struct Node *h ) {
     if(h == NULL)
	{
	return;
	}
	if ( h != NULL ) {
        printf ( "%d->", h->data );
        if(h->left)
	print ( h->left );
        if(h->right)
	print ( h->right );
    }
  //  printf ( "\n" );
}
/*
int main() {
	struct Node *h;
h = insert ( h, 1 );
//print(h);
h = insert ( h, 5 );
//print (h);
h = insert ( h, 9 );
//print(h);
h = insert ( h, 3 );*/
