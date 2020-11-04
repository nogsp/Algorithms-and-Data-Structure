#include <stdio.h>
#include <stdlib.h>
#define E int

/******* STRUCTURES *********/
struct Link {
    E element;
    struct Link *next;
}; typedef struct Link Link;

struct List {
    Link *head, *tail, *curr;
    int cnt;
}; typedef struct List List;

/*** FUNCITONS PROTOTYPES ***/
Link* createLink(E it, Link *nextval);
List* createList();
void insert(List* l, E it);
int delete(List *l);
void moveToStart(List *l);
void moveToEnd(List *l);
void prev(List *l);
void next(List *l);
int currPos(List *l);
int moveToPos(List *l, int pos);
E getValue(List *l);
/*functions prototypes user frinedly*/
void clear();
void append(List *l, E item);
int length(List* l);
E at(List *l, int it);
int insertAt(List *l, E it, int pos);
int deleteAt(List *l, int pos);
int empty(List *l);
void printList(List *l);

/****************************/

int main() {
    List *lista = createList();
    append(lista, 1);
    append(lista, 3);
    insertAt(lista, 2, 1);
    printList(lista);
    printf("%d\n", length(lista));
    deleteAt(lista, 1);
    printList(lista);
    printf("%d\n", length(lista));
}

/***** FUNCTION BODIES ******/
Link* createLink(E it, Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

List* createList() {
    List *l = (List*)malloc(sizeof(List));
    l->head = createLink(-1,NULL);
    l->curr = l->tail = l->head;
    l->cnt = 0;
    return l;
}

void clear(List *l) {
    l->head = createLink(-1, NULL);
    l->curr = l->tail = l->head;
    l->cnt = 0;
}

void insert(List* l, E it) {
    l->curr->next = createLink(it,l->curr->next);
    if(l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void append(List *l, E it) {
    l->tail->next =createLink(it, NULL);
    l->tail = l->tail->next;
    l->cnt++;
}

int delete(List *l) {
    if(l->curr->next == NULL) return 0;
    if(l->tail == l->curr->next) {
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return 1;
}

void moveToStart(List *l) {
    l->curr = l->head;
}

void moveToEnd(List *l) {
    l->curr = l->tail;
}

void prev(List *l) {
    if(l->curr == l->head) return;
    Link *temp = l->head;
    while(temp->next != l->curr) {
        temp = temp->next;
    } 
    l->curr = temp;
}

void next(List *l) {
    if(l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

int length(List *l) {
    return l->cnt;
}

int currPos(List *l) {
    Link *temp = l->head;
    int i = 0;
    while(temp != l->curr) {
        temp = temp->next;
        i++;
    }
    return i;
}

int moveToPos(List *l, int pos) {
    if(pos < 0 || pos >= length(l)) return 0;
    l->curr = l->head;
    int i = 0;
    while(i < pos) {
        l->curr = l->curr->next;
        i++;
    }
    return 1;
}

E getValue(List *l) {
    if(l->curr->next == NULL) {
        return l->curr->element;
    }    
    return l->curr->next->element;
}

E at(List *l, int it) {
    Link *temp = l->curr;
    if(moveToPos(l, it)) {
        E val = getValue(l);
        l->curr = temp;
        return val;
    } else {
        printf("Posição invalida\n");
        return -123456789;
    }
}

int insertAt(List *l, E it, int pos) {
    Link *temp = l->curr;
    if(moveToPos(l, pos)) {
        insert(l, it);
        l->curr = temp;
        return 1;
    } else {
        return 0;
    }
}

int deleteAt(List *l, int pos) {
    Link *temp = l->curr;
    if(moveToPos(l, pos)) {
        delete(l);
        l->curr = temp;
        return 1;
    } else {
        return 0;
    }
}

int empty(List *l) {
    if(l->cnt > 0) return 1;
    return 0;
}

void printList(List *l) {
    Link *temp = l->head;
    while(temp->next != NULL) {
        printf("%d ", temp->next->element);
        temp = temp->next;
    }
    printf("\n");
}