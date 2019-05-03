#include<stdio.h>
#define size 5
struct queue{
char a[size][100];
int front;
int rear;
};
typedef struct queue queue;
void enqueue(queue*q,char a[])
{
    if((q->rear+1)%size==q->front)
        printf("queue full\n");
    else
        {
            strcpy(q->a[(++q->rear)%size],a);
            if(q->front==-1)
                q->front=0;
        }
}
void deque(queue*q)
{
    if(q->front==q->rear==-1)
        printf("queue empty");
    else{
        if(q->front!=q->rear)
        printf("%s",q->a[(q->front++)%size]);
        else
        {
            printf("%s",q->a[(q->front)]);
            q->front=q->rear=-1;
        }
    }
}
void display(queue q)
{
    int i;
    if(q.front==q.rear)
        printf("%s",q.a[q.front]);
    else if(q.rear>q.front)
        for(i=q.front;i<=q.rear;i++)
            printf("%s",q.a[i]);
    else{
        for(i=q.front;i<size;i++)
            printf("%s",q.a[i]);
        for(i=0;i<=q.rear;i++)
            printf("%s",q.a[i]);
        }
}
int main()
{
    queue q;
    q.front=q.rear=-1;
    int ch;
    int a[100];
    while(1)
    {
        printf("\n 1:send 2:recieve 3:display 4:exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter the string");
            getchar();
            scanf("%[^\n]s",a);
            enqueue(&q,a);
        }
        if(ch==2)
            deque(&q);
        if(ch==3)
            display(q);
        if(ch==4)
            break;
        }
    return 0;
}
