#include<stdio.h>
struct tree{
struct tree*left;
struct tree*right;
int d;
};
typedef struct tree tree;
tree*insert(tree*root,int d)
{
    tree*temp;
    temp=(tree*)malloc(sizeof(tree));
    temp->d=d;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        return temp;
    else if(root->d>d&&root->left!=NULL)
        root->left=insert(root->left,d);
    else if(root->d<d&&root->right!=NULL)
        root->right=insert(root->right,d);
    else{
        if(root->d>d)
            root->left=temp;
        else
            root->right=temp;
        }
    return root;
}
int max(tree*root)
{
    tree*t;
    t=root;
    while(t->right!=NULL)
        t=t->right;
    return t->d;
}
tree*delet(tree*root,int d)
{
    int m;
    if(root==NULL)
        return NULL;
    else if(root->d<d)
        root->right=delet(root->right,d);
    else if(root->d>d)
        root->left=delet(root->left,d);
    else{
        if(root->left==NULL&&root->right==NULL)
            root=NULL;
        else if(root->left==NULL&&root->right!=NULL)
            root=root->right;
        else if(root->left!=NULL&&root->right==NULL)
            root=root->left;
        else{
            m=max(root->right);
            root->d=m;
            root->right=delet(root->right,m);
            }
        }
    return root;
}
void inorder(tree*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->d);
    inorder(root->right);
}
void postorder(tree*root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->d);
}
void preorder(tree*root)
{
    if(root==NULL)
        return;
    printf("%d",root->d);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    tree*root;
    root=NULL;
    int ch;
    int d;
    while(1)
    {
        printf("1:insert 2:delete 3:inorder 4:preorder 5:postoredr 6:exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("entre number\n");
            scanf("%d",&d);
            root=insert(root,d);
        }
        if(ch==2)
        {
            printf("entre no to delete\n");
            scanf("%d",&d);
            root=delet(root,d);
        }
        if(ch==3)
            inorder(root);
        if(ch==4)
            preorder(root);
        if(ch==5)
            postorder(root);
        if(ch==6)
            break;
        }
    return 0;
}
