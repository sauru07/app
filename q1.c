#include <stdio.h>
#define max 5

struct queue { int item[max], rear, front; };

void create(struct queue *q)
{
    q->rear = q->front = -1;
}

void insert(struct queue *q, int n)
{
    if(q->rear == max-1) printf("Queue is full");
    else q->item[++q->rear] = n;
}

int delete(struct queue *q)
{
    if(q->front == q->rear) {
        printf("Queue is empty");
        return -1;
    }
    return q->item[++q->front];
}

void display(struct queue *q)
{
    int i;
    if(q->front == q->rear) printf("Queue is empty");
    else
        for(i=q->front+1; i<=q->rear; i++)
            printf("%d ",q->item[i]);
}

void isFull(struct queue *q)
{
    if(q->rear == max-1) printf("Queue is full");
    else printf("Queue is not full");
}

void isEmpty(struct queue *q)
{
    if(q->front == q->rear) printf("Queue is empty");
    else printf("Queue is not empty");
}

int main()
{
    struct queue p, *q=&p;
    int ch,n;

    do {
        printf("\n1.create\n2.insert\n3.display\n4.remove");
        printf("\n5.IS empty\n6.Is full\n7.Exit");
        printf("\nEnter choice :");
        scanf("%d",&ch);

        switch(ch) {
            case 1: create(q); break;
            case 2:
                printf("Enter a number :");
                scanf("%d",&n);
                insert(q,n);
                break;
            case 3: display(q); break;
            case 4:
                n=delete(q);
                if(n!=-1) printf("Popped : %d",n);
                break;
            case 5: isEmpty(q); break;
            case 6: isFull(q); break;
            case 7: printf("Exited..."); break;
        }
    } while(ch!=7);

    return 0;
}