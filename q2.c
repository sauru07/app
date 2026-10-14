#include <stdio.h>
#define max 5

struct queue { int item[max],front,rear; };

void create(struct queue *q)
{
    q->front=q->rear=-1;
}

void insert(struct queue *q,int n)
{
    if((q->rear+1)%max==q->front) { printf("Queue is full"); return; }

    if(q->front==-1) q->front=q->rear=0;
    else q->rear=(q->rear+1)%max;

    q->item[q->rear]=n;
}

int delete(struct queue *q)
{
    int n;
    if(q->front==-1) { printf("Queue is empty"); return -1; }

    n=q->item[q->front];

    if(q->front==q->rear) q->front=q->rear=-1;
    else q->front=(q->front+1)%max;

    return n;
}

void display(struct queue *q)
{
    int i;
    if(q->front==-1) { printf("Queue is empty"); return; }

    i=q->front;
    while(1)
    {
        printf("%d ",q->item[i]);
        if(i==q->rear) break;
        i=(i+1)%max;
    }
}

void isFull(struct queue *q)
{
    printf((q->rear+1)%max==q->front ?
           "Queue is full":"Queue is not full");
}

void isEmpty(struct queue *q)
{
    printf(q->front==-1 ?
           "Queue is empty":"Queue is not empty");
}

int main()
{
    struct queue p,*q=&p;
    int ch,n;

    do {
        printf("\n1.create\n2.insert\n3.display\n4.remove");
        printf("\n5.IS empty\n6.Is full\n7.Exit");
        printf("\nEnter choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create(q); break;
            case 2:printf("Enter a number :");scanf("%d",&n);
                   insert(q,n); break;
            case 3:display(q); break;
            case 4:n=delete(q); if(n!=-1) printf("Popped : %d",n); break;
            case 5:isEmpty(q); break;
            case 6:isFull(q); break;
            case 7:printf("Exited...");
        }
    }while(ch!=7);

    return 0;
}