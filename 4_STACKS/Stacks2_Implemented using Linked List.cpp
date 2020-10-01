///Stack Linked List CPP

#include<iostream>
using namespace std;
class Node
{
    public:
        int info;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void Display();
};

void Stack::push(int data)
{
    Node *temp=new Node;
    if(temp==NULL)
    {
        cout<<"Stack is Full\n";
    }
    else
    {
        temp->info=data;
        temp->next=top;
        top=temp;
    }
}

int Stack::pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack is Empty\n";
    }
    else
    {
        x=top->info;
        Node *temp=top;
        top=top->next;
        delete temp;
    }
    return x;
}
void Stack::Display()
{
Node *p=top;
while(p!=NULL)
{
cout<<p->info<<" ";
p=p->next;
}
cout<<endl;
}
int main()
{
Stack stk;
stk.push(10);
stk.push(20);
stk.push(30);
stk.push(40);
cout<<"\n Stack Contents : ";
stk.Display();
cout<<stk.pop();
cout<<"\n Stack Contents : ";
stk.Display();
return 0;
}
