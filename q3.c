#include <stdio.h>
#define max 5

struct queue { int item[max],front,rear; };

void create(struct queue *q)
{
    q->front=q->rear=-1;
}

void insert(struct queue *q,int n)
{
    if(q->rear==max-1) { printf("Queue is full"); return; }

    q->item[++q->rear]=n;
    if(q->front==-1) q->front=0;
}

int deleteFront(struct queue *q)
{
    int n;
    if(q->front==-1) { printf("Queue is empty"); return -1; }

    n=q->item[q->front++];

    if(q->front>q->rear) q->front=q->rear=-1;
    return n;
}

int deleteRear(struct queue *q)
{
    int n;
    if(q->front==-1) { printf("Queue is empty"); return -1; }

    n=q->item[q->rear--];

    if(q->rear<q->front) q->front=q->rear=-1;
    return n;
}

void display(struct queue *q)
{
    int i;
    if(q->front==-1) { printf("Queue is empty"); return; }

    for(i=q->front;i<=q->rear;i++) printf("%d ",q->item[i]);
}

void isFull(struct queue *q)
{
    printf(q->rear==max-1 ?
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
        printf("\n1.create\n2.insert\n3.display");
        printf("\n4.delete from front\n5.delete from rear");
        printf("\n6.is empty\n7.is full\n8.exit");
        printf("\nEnter choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create(q); break;
            case 2:printf("Enter a number :");scanf("%d",&n);
                   insert(q,n); break;
            case 3:display(q); break;
            case 4:n=deleteFront(q); if(n!=-1) printf("Deleted : %d",n); break;
            case 5:n=deleteRear(q); if(n!=-1) printf("Deleted : %d",n); break;
            case 6:isEmpty(q); break;
            case 7:isFull(q); break;
            case 8:printf("Exited...");
        }
    }while(ch!=8);

    return 0;
}