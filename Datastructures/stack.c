#include<stdio.h>
#define size 5
struct stack{
int top;
int a[size];
};
typedef struct stack stack;
void push(stack*s,int e)
{
    if(s->top==size-1)
        printf("stack full\n");
    else
        s->a[++s->top]=e;
}
int pop(stack*s)
{
    if(s->top==-1)
        printf("stack empty\n");
    else
        return s->a[s->top--];
}
void display(stack s)
{
    int i;
    i=s.top;
    for(;i>=0;i--)
        printf("%d\n",s.a[i]);
}
int top3(stack*s)
{
    if(s->top<2)
        printf("invalid\n");
    stack temp;
    temp.top=-1;
    int i;
    for(i=0;i<2;i++)
        push(&temp,pop(s));
    int y;
    y=s->a[s->top];
    while(temp.top!=-1)
        push(s,pop(&temp));
    return y;
}
int bot3(stack*s)
{

    if(s->top<2)
        printf("invalid\n");
    stack temp;
    temp.top=-1;
    int i;
    while(s->top!=2)
        push(&temp,pop(s));
    int y;
    y=s->a[s->top];
    while(temp.top!=-1)
        push(s,pop(&temp));
    return y;
}
int main()
{
    stack s;
    s.top=-1;
    int ch;
    int n,i;
    int ele;
    while(1)
    {
        printf("1:insert 2:delete 3:display 4:popn 5:top3 6:bot3 7:exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter the number\n");
            scanf("%d",&ele);
            push(&s,ele);
        }
        if(ch==2)
        {
            ele=pop(&s);
            printf("%d\n",ele);
        }
        if(ch==3)
            display(s);
        if(ch==4)
        {
            printf("enter n\n");
            scanf("%d",&n);
            if(n>s.top-1)
                printf("invalid\n");
            else
                for(i=0;i<n;i++)
                    printf("%d\n",pop(&s));
        }
        if(ch==5)
            printf("%d",top3(&s));
        if(ch==6)
            printf("%d",bot3(&s));
        if(ch==7)
            break;
        }
    return 0;
}
