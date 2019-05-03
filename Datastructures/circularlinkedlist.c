#include<stdio.h>
struct node{
int d;
struct node*next;
};
typedef struct node node;
node*insertbegin(node*h1,int d)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->d=d;
    temp->next=NULL;
    if(h1==NULL)
        return temp;
    temp->next=h1->next;
    h1->next=temp;
    return h1;
}
node*add(node*h1,node*h2,node*h3)
{
    node*t1;
    node*t2;
    t1=h1->next;
    t2=h2->next;
    int c,t,s;
    c=0;
    while(t1!=h1)
    {
        t=t1->d+t2->d+c;
        s=t%10;
        c=t/10;
        h3=insertbegin(h3,s);
        t2=t2->next;
        t1=t1->next;
    }
    h3=insertbegin(h3,c);
return h3;
}
void display(node*h3)
{
    node*t1;
    t1=h3->next;
    while(t1!=h3)
        {
            printf("%d",t1->d);
            t1=t1->next;
        }
}
int main()
{
    node*h1;
    node*h2;
    node*h3;
    h1=(node*)malloc(sizeof(node));
    h2=(node*)malloc(sizeof(node));
    h3=(node*)malloc(sizeof(node));
    h1->next=h1;
    h2->next=h2;
    h3->next=h3;
    char n1[100];
    char n2[100];
    int l1,l2;
    printf("enter first number\n");
        scanf("%s",n1);
    printf("enter second number\n");
        scanf("%s",n2);
    l1=strlen(n1);
    l2=strlen(n2);
    int i;
    if(l1>l2)
        for(i=0;i<l1-l2;i++)
            h2=insertbegin(h2,0);
    if(l2>l1)
        for(i=0;i<l2-l1;i++)
            h1=insertbegin(h1,0);
    for(i=0;i<l1;i++)
        h1=insertbegin(h1,n1[i]-'0');
    for(i=0;i<l2;i++)
        h2=insertbegin(h2,n2[i]-'0');
    add(h1,h2,h3);
    display(h3);
    return 0;
}
