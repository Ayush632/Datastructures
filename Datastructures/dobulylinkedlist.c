#include<stdio.h>
struct node{
int r;
int c;
int v;
struct node*right;
struct node*left;
};
typedef struct node node;
node*insertbegin(node*s1,int r,int c,int v)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->r=r;
    temp->c=c;
    temp->v=v;
    temp->left=temp->right=NULL;
    if(s1==NULL)
        return temp;
    if(s1->right!=NULL)
        s1->right->left=temp;
    temp->right=s1->right;
    s1->right=temp;
    temp->left=s1;
    return s1;
}
void display(node*s,int r,int c)
{
    node*t;
    t=s;
    while(t!=NULL)
    {
        if(t->r==r&&t->c==c)
        {
            printf("%d",t->v);
            return ;
        }
        t=t->right;
    }
    printf("0");
}
int main()
{
    int m,n;
    node*s1;
    int r,c,v,i,j;
    s1=NULL;
    printf("enter the dimensions of the matrix\n");
    scanf("%d%d",&m,&n);
    int ch;
    while(1)
    {
        printf("\nDo you want to insert\n1:yes 2:no\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter row,cloumn,value\n");
            scanf("%d%d%d",&r,&c,&v);
            s1=insertbegin(s1,r,c,v);
        }
        if(ch==2)
            break;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            display(s1,i,j);
        printf("\n");
    }
    return 0;
}
