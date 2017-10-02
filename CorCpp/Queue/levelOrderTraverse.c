#include<stdio.h>
#include "queue.h"
#include "binTree.h"

struct Node* createTree () {
    struct Node* h = NULL;
    h = insert (h, 5); 
    h = insert (h, 3);
    h = insert (h, 2);
    h = insert (h, 4);
    h = insert (h, 7);
    h = insert (h, 6);
    h = insert (h, 9);
    h = insert (h, 8);
    return h;
}

void levelOrder ( struct Node *h, struct queue *q ) {
    enQ(q, h->data);
    while (q->rear != NULL) {
        struct Node *t = deQ(q);
        print ( t );
        if ( t->left )
            enQ(q, t->left->data);
        if ( t->right )
            enQ(q, t->right->data);
    }
}

int main() {
    struct Node *h = createTree ();
    struct queue *q = createQ();
    /*
    h = insert (h, 3);
    h = insert (h, 2);
    h = insert (h, 4);
    h = insert (h, 7);
    h = insert (h, 6);
    h = insert (h, 9);
    h = insert (h, 8);
    */
    printf ("\n\nprinting h\n\n");
    print ( h );
    levelOrder ( h, q );
return 0;
}
