#include <stdio.h>
#include <stdlib.h>
#define E int

/******* STRUCTURES *********/
struct Link {
    E element;
    struct Link *next;
}; typedef struct Link Link;

struct Stack {
    Link *top;
    int cnt;
}; typedef struct Stack Stack;

/*** FUNCITONS PROTOTYPES ***/
Link* createLink(E it, Link *nextval);
Stack* createStack();
/*functions prototypes user frinedly*/
void clear();
void push(Stack *s, E item);
int pop(Stack *s);
E top(Stack *s);
int length(Stack *s);
int empty(Stack *s);
void printStack(Stack *l);

/****************************/

int main() {
    int i;
    Stack *Stack = createStack();
    push(Stack, 5);
    push(Stack, 4);
    push(Stack, 3);
    push(Stack, 2);
    push(Stack, 1);
    for(i = 0; i < 5; i++) {
        printStack(Stack);
        printf("%d\n", length(Stack));
        pop(Stack);
    }
    
}

/***** FUNCTION BODIES ******/
Link* createLink(E it, Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->cnt = 0;
    return s;
}

void clear(Stack *s) {
    s->top = NULL;
    s->cnt = 0;
}

void push(Stack *s, E it) {
    s->top = createLink(it, s->top);
    s->cnt++;
}

int pop(Stack *s) {
    if(s->top == NULL) return 0;
    s->top = s->top->next;
    s->cnt--;
    return 1;
}

E top(Stack *s) {
    if(s->top == NULL) {
        printf("The Stack is empty!!!\n");
        return 0;
    } else {
        return s->top->element;
    }
}

int length(Stack *s) {
    return s->cnt;
}

int empty(Stack *s) {
    if(s->cnt > 0) return 1;
    return 0;
}

void printStack(Stack *s) {
    Link *temp = s->top;
    while(temp != NULL) {
        printf("%d ", temp->element);
        temp = temp->next;
    }
    printf("\n");
}