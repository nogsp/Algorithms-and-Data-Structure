#include <stdio.h>
#include <stdlib.h>
#define E int

/******* STRUCTURES *********/
struct Link {
    E element;
    struct Link *next;
}; typedef struct Link Link;

struct Queue {
    Link *front, *rear;
    int cnt;
}; typedef struct Queue Queue;

/*** FUNCITONS PROTOTYPES ***/
Link* createLink(E it, Link *nextval);
Queue* createQueue();
/*functions prototypes user frinedly*/
void clear();
void push(Queue *q, E item);
int pop(Queue *q);
E front(Queue *q);
int length(Queue *q);
int empty(Queue *q);
void printQueue(Queue *q);

/****************************/

int main() {
    int i;
    Queue *Queue = createQueue();
    push(Queue, 5);
    push(Queue, 4);
    push(Queue, 3);
    push(Queue, 2);
    push(Queue, 1);
    for(i = 0; i < 5; i++) {
        printQueue(Queue);
        printf("%d\n", length(Queue));
        pop(Queue);
    }
    
}

/***** FUNCTION BODIES ******/
Link* createLink(E it, Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = createLink(-1, NULL);
    q->cnt = 0;
    return q;
}

void clear(Queue *q) {
    q->front = q->rear = createLink(-1, NULL);
    q->cnt = 0;
}

void push(Queue *q, E it) {
    q->rear->next = createLink(it, NULL);
    q->rear = q->rear->next;
    q->cnt++;
}

int pop(Queue *q) {
    if(q->cnt <= 0) return 0;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL) {
        q->rear = q->front;
    }    
    q->cnt--;
    return 1;
}

E front(Queue *q) {
    if(q->cnt <= 0) {
        printf("The Queue is empty!!!\n");
        return 0;
    } else {
        return q->rear->element;
    }
}

int length(Queue *q) {
    return q->cnt;
}

int empty(Queue *q) {
    if(q->cnt > 0) return 1;
    return 0;
}

void printQueue(Queue *q) {
    Link *temp = q->front;
    while(temp->next != NULL) {
        printf("%d ", temp->next->element);
        temp = temp->next;
    }
    printf("\n");
}