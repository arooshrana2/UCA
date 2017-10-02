#include<stdlib.h>
struct queue {
    struct que *front;
    struct que *rear;
};

struct que {
    int val;
    struct que *next;
};


struct queue* createQ() {
    struct queue *qu = (struct queue*) malloc (sizeof(struct queue));
    qu->front = qu->rear = NULL;
    return qu;
}

struct que* newNode (int x) {
    struct que *newNode = (struct que*) malloc (sizeof(struct que));
    newNode->next = NULL;
    newNode->val = x;
    return newNode;
}
void enQ ( struct queue *q, int x ) {
    struct queue *qq = newNode(x);
    if( q->rear == NULL) {
        q->front = q->rear = qq;
        return;
    }
    q->rear->next = qq;
    q->rear = qq;
}
struct que* deQ ( struct queue *q ) {
    if (q->front == NULL)
        return NULL;
    struct que *temp = q->front;
    q->front = q->front->next;
    if ( q->front == NULL )
        q->rear = NULL;
    return temp;
}
/*
int main(){
    struct queue *q = createQ();
    enQ(q, 10);
    enQ(q, 20);
    enQ(q, 30);
    printf ("%d\n", (deQ(q))->val);
return 0;
}
*/

