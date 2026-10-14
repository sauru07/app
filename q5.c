#include <stdio.h>
#define max 5

struct queue { int item[max], priority[max], rear; };

void create(struct queue *q)
{
    q->rear = -1;
}

void insert(struct queue *q, int n, int p)
{
    int i;

    if(q->rear == max-1)
    {
        printf("Queue is full");
        return;
    }

    i = q->rear;

    while(i >= 0 && q->priority[i] > p)
    {
        q->item[i+1] = q->item[i];
        q->priority[i+1] = q->priority[i];
        i--;
    }

    q->item[i+1] = n;
    q->priority[i+1] = p;
    q->rear++;
}

int delete(struct queue *q)
{
    int n, i;

    if(q->rear == -1)
    {
        printf("Queue is empty");
        return -1;
    }

    n = q->item[0];

    for(i=0; i<q->rear; i++)
    {
        q->item[i] = q->item[i+1];
        q->priority[i] = q->priority[i+1];
    }

    q->rear--;

    return n;
}

void display(struct queue *q)
{
    int i;

    if(q->rear == -1)
    {
        printf("Queue is empty");
        return;
    }

    for(i=0; i<=q->rear; i++)
        printf("%d(P%d) ",q->item[i],q->priority[i]);
}

void isFull(struct queue *q)
{
    printf(q->rear==max-1 ?
           "Queue is full":"Queue is not full");
}

void isEmpty(struct queue *q)
{
    printf(q->rear==-1 ?
           "Queue is empty":"Queue is not empty");
}

int main()
{
    struct queue p,*q=&p;
    int ch,n,pr;

    do
    {
        printf("\n1.create\n2.insert\n3.delete\n4.display");
        printf("\n5.is empty\n6.is full\n7.Exit");
        printf("\nEnter choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                create(q);
                break;

            case 2:
                printf("Enter number :");
                scanf("%d",&n);
                printf("Enter priority :");
                scanf("%d",&pr);
                insert(q,n,pr);
                break;

            case 3:
                n=delete(q);
                if(n!=-1) printf("Deleted : %d",n);
                break;

            case 4:
                display(q);
                break;

            case 5:
                isEmpty(q);
                break;

            case 6:
                isFull(q);
                break;

            case 7:
                printf("Exited...");
        }

    }while(ch!=7);

    return 0;
}