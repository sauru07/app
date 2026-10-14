#include <stdio.h>
#define max 5

struct queue { int item[max],front,rear; };

void create(struct queue *q)
{
    q->front=q->rear=-1;
}

void insertRear(struct queue *q,int n)
{
    if(q->rear==max-1) { printf("Queue is full"); return; }

    if(q->front==-1) q->front=0;
    q->item[++q->rear]=n;
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

void insertFront(struct queue *q,int n)
{
    int i;

    if(q->front==0) { printf("Front insertion not possible"); return; }

    if(q->front==-1)
        q->front=q->rear=0;
    else
    {
        for(i=q->rear;i>=q->front;i--)
            q->item[i+1]=q->item[i];
        q->item[q->front]=n;
        q->rear++;
    }
}

void display(struct queue *q)
{
    int i;
    if(q->front==-1) { printf("Queue is empty"); return; }

    for(i=q->front;i<=q->rear;i++)
        printf("%d ",q->item[i]);
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

    do
    {
        printf("\n1.create\n2.insert rear\n3.insert front");
        printf("\n4.delete front\n5.delete rear\n6.display");
        printf("\n7.is empty\n8.is full\n9.Exit");
        printf("\nEnter choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create(q); break;

            case 2:
                printf("Enter a number :"); scanf("%d",&n);
                insertRear(q,n); break;

            case 3:
                printf("Enter a number :"); scanf("%d",&n);
                insertFront(q,n); break;

            case 4:
                n=deleteFront(q);
                if(n!=-1) printf("Deleted : %d",n);
                break;

            case 5:
                n=deleteRear(q);
                if(n!=-1) printf("Deleted : %d",n);
                break;

            case 6: display(q); break;
            case 7: isEmpty(q); break;
            case 8: isFull(q); break;
            case 9: printf("Exited...");
        }

    }while(ch!=9);

    return 0;
}