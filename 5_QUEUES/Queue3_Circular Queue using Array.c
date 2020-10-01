//Circular Queue
#include <stdio.h>
#include <stdlib.h>
struct Queue
{
int size;
int front;
int rear;
int *Q;
};
void create(struct Queue *q,int size)
{
q->size=size;
q->front=q->rear=0;
q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue *q,int x)
{
if((q->rear+1)%q->size==q->front)
printf("Queue is Full\n\n");
else
{
q->rear=(q->rear+1)%q->size;
q->Q[q->rear]=x;
}
}
int dequeue(struct Queue *q)
{
int x=-1;
if(q->front==q->rear)
printf("Queue is Empty\n");
else
{
x=q->Q[q->front];
q->front=(q->front+1)%q->size;

}
return x;
}
void Display(struct Queue q)
{
int i=q.front+1;
do
{
printf("%d ",q.Q[i]);
i=(i+1)%q.size;
}while(i!=(q.rear+1)%q.size);
printf("\n");
}
int main()
{
struct Queue q;
create(&q,5);
enqueue(&q,10);
enqueue(&q,20);
enqueue(&q,30);
Display(q);
enqueue(&q,40);
Display(q);
enqueue(&q,50);
printf("\n\n Enqueued 50 now : \n");
Display(q);
enqueue(&q,60);
printf("\n\n Enqueued 60 now : \n");

Display(q);
printf("\n\n Dequeue operation  : \n");
printf("%d ",dequeue(&q));
Display(q);
return 0;
}
