#include<stdio.h>
struct node{
int co;
int po;
struct node*next;
};
typedef struct node node;
node*insertbegin(node*start,int co,int po)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;
    if(start==NULL)
    return temp;
    temp->next=start->next;
    start->next=temp;
    return start;
}
node*mul(node*s1,node*s2,node*s3)
{
    node*t1;
    node*t2;
    t1=s1;
    int po;
    int co;
    while(t1!=NULL)
    {
        t2=s2;
        while(t2!=NULL)
        {
            s3=insertbegin(s3,t1->co*t2->co,t1->po+t2->po);
            t2=t2->next;
        }
        t1=t1->next;
    }
    return s3;
}
node*add(node*s3)
{
    node*t1;
    node*t2;
    node*prev;
    t1=s3;
    while(t1!=NULL)
    {
        t2=t1->next;
        prev=t1;
        while(t2!=NULL)
        {
            if(t2->po==t1->po)
            {
                t1->co=t1->co+t2->co;
                prev->next=t2->next;
            }
            prev=t2;
            t2=t2->next;
        }
        t1=t1->next;
    }
    return s3;
}
void display(node*s3)
{
    printf("%dx^%d",s3->co,s3->po);
    node*t;
    t=s3->next;
    while(t!=NULL)
    {
        if(t->co>=0)
            printf("+%dx^%d",t->co,t->po);
        else
            printf("%dx^%d",t->co,t->po);
        t=t->next;
    }
}
int main()
{
    int n,i;
    int co,po;
    node*s1;
    node*s2;
    node*s3;
    s1=s2=s3=NULL;
    printf("entrer no of terms in p1\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("entre co and powre\n");
        scanf("%d%d",&co,&po);
        s1=insertbegin(s1,co,po);
    }
    printf("entrer no of terms in p2\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("entre co and powre\n");
        scanf("%d%d",&co,&po);
        s2=insertbegin(s2,co,po);
    }
    s3=mul(s1,s2,s3);
    s3=add(s3);
    display(s3);
}
