#include<stdio.h>
struct tree{
struct tree*left;
struct tree*right;
char a;
};
typedef struct tree tree;
int preceed(char a)
{
    switch(a)
    {
        case '+':
        case'-':return 1;
        case'0':return 0;
        case'*':
        ;case'/':return 2;
        case'^':return 3;
    }
}
int check(char a, char b)
{
    if(preceed(a)>preceed(b)||(preceed(a)==preceed(b)&&preceed(a)==3))
        return 0;
    else
        return 1;
}
void inorder(tree*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%c",root->a);
    inorder(root->right);
}
void preorder(tree*root)
{
     if(root==NULL)
        return;
    printf("%c",root->a);
    preorder(root->left);
    preorder(root->right);
}
void postorder(tree*root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->a);
}
int main()
{
    char infix[100];
    tree*t1;
    tree*t2;
    tree*t3;
    int i,l;
    int top1,top2;
    top1=-1;
    top2=-1;
    tree*oper[100];
    tree*opnd[100];
    tree*temp;
    printf("enter infix expression\n");
    scanf("%s",infix);
    l=strlen(infix);
    for(i=l-1;i>=0;i--)
    {
        temp=(tree*)malloc(sizeof(tree));
        temp->a=infix[i];
        temp->left=temp->right=NULL;
        if(isalnum(infix[i]))
            opnd[++top1]=temp;
        else{
            while(top2!=-1&&check(infix[i],oper[top2]->a))
            {
                t1=opnd[top1--];
                t2=opnd[top1--];
                t3=oper[top2--];
                t3->left=t1;
                t3->right=t2;
                opnd[++top1]=t3;
            }
            oper[++top2]=temp;
        }
    }
        while(top2!=-1)
        {
            t1=opnd[top1--];
            t2=opnd[top1--];
            t3=oper[top2--];
            t3->left=t1;
            t3->right=t2;
            opnd[++top1]=t3;
        }
        int ch;
      /*  inorder(opnd[top1]);
        preorder(opnd[top1]);
        postorder(opnd[top1]);*/
        while(1)
        {
            printf("1:infix 2:prefix 3:postfix 4:exit\n");
            scanf("%d",&ch);
            if(ch==1)
                inorder(opnd[top1]);
            if(ch==2)
                preorder(opnd[top1]);
            if(ch==3)
                postorder(opnd[top1]);
            if(ch==4)
                break;
            }
        return 0;
    }
