#include <iostream>
#define INF 0x3f3f3f

using namespace std;

struct queue{
    int val;
    queue *next;
};
int ctn=0;
bool empty(queue *turn){
    if(turn->next==nullptr){
        return true;
    }
    else{
        return false;
    }
}

queue *new_queue(){
    queue * turn=nullptr;
    turn = new queue;
    turn->next = nullptr;
    turn->val = INF;
    return turn;
}

queue *create_member(queue *turn, int val){
    queue *m=nullptr;
    m = new queue;
    m->val = val;
    m->next=nullptr;
    return m;
}

queue *new_member(queue *turn, int val){
    queue *curr=turn;
    while(!empty(curr)){
        curr = curr->next;
    }
    curr->next = create_member(turn, val);
    ctn++;
    return turn; 
}

queue *pop_member(queue *turn){
    queue *temp=turn;
    turn = turn->next;
    delete temp;
    ctn--;
    return turn;
}

void show(queue *turn){
    queue *curr=turn;
    while(!empty(curr)){
        curr = curr->next;
        cout << curr->val << " ";
    }
    cout <<"final da fila com: " << ctn << " membros" << endl;
}

int main(void){
    queue *turn = new_queue();
    turn = new_member(turn, 1);
    show(turn);
    turn = new_member(turn, 2);
    show(turn);
    turn = new_member(turn, 3);
    show(turn);
    turn = new_member(turn, 4);
    show(turn);
    turn = new_member(turn, 5);
    show(turn);
    turn = pop_member(turn);
    show(turn);
    turn = pop_member(turn);
    show(turn);
    turn = pop_member(turn);
    show(turn);
    turn = pop_member(turn);
    show(turn);
    turn = pop_member(turn);
    show(turn);

    return 0;
}