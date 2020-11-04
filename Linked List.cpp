#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;

struct lista {
	int val;
	lista *next;
};

int ctn=0;

lista *create_list(){
	lista *head=nullptr;
	head = new lista;
	head->val = INF;
	head->next=nullptr;
	return head;
}

bool empty(lista *head){
	if(head->next==nullptr){
		return true;
	}
	else{
		return false;
	}
}

lista *create_node(int val){
	lista *node=nullptr;
	node = new lista;
	node->val = val;
	node->next=nullptr;
	return node;
}

lista *create_node(int val, lista *nextval){
	lista *node=nullptr;
	node = new lista;
	node->val = val;
	node->next=nextval;
	return node;
}

void push_up(lista *head, int val){
	lista *curr=head;
	curr->next = create_node(val, curr->next);
	ctn++;
}

void push_back(lista *head, int val){
	lista *curr=head;
	while(!empty(curr)){
		curr = curr->next;
	}
	curr->next = create_node(val);
	ctn++;
}

void push_select(lista *head, int val, int pos){
	lista *curr=head;
	while(pos-- && !empty(curr)){
		curr = curr->next;
	}
	curr->next = create_node(val, curr->next);
	ctn++;
}

void pop_up(lista *head){
	if(ctn>0){	
		lista *curr=head;
		lista *old=head;
		curr = curr->next;
		old->next=curr->next;
		delete curr;
		ctn--;
	}	
}

void pop_back(lista *head){
	if(ctn>0){
		lista *curr=head;
		lista *old=head;
		while(!empty(curr)){
			old = curr;
			curr = curr->next;
		}
		old->next=nullptr;
		delete curr;
		ctn--;
	}
}

void pop_select(lista *head, int pos){
	if(ctn>0){	
		lista *curr=head;
		lista *old=head;
		while(pos-- && !empty(curr)){
			old = curr;
			curr = curr->next;
		}
		old->next = curr->next;
		delete curr;
		ctn--;
	}	
}

void show(lista *head){
	lista *curr=head;
	while(!empty(curr)){
		curr = curr->next;
		cout << curr->val << "-";
	}
	cout << "--null with: " << ctn << " elements" <<endl;
}

int main(void){
	lista *head = create_list();
	push_back(head,25);
	show(head);
	push_back(head,26);
	show(head);
	push_back(head,27);
	show(head);
	cout << endl;
	push_up(head,3);
	show(head);
	push_up(head,2);
	show(head);
	push_up(head,1);
	show(head);
	cout << endl;
	push_select(head, 101, 0);
	show(head);
	push_select(head, 102, 3);
	show(head);
	push_select(head, 103, 20);
	show(head);
	cout << endl;
	pop_up(head);
	show(head);
	pop_back(head);
	show(head);
	pop_select(head,3);
	show(head);
	while(!empty(head)){
		cout << endl;
		pop_back(head);
		pop_up(head);
		show(head);
	}

	return 0;
}
