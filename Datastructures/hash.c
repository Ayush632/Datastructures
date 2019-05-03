#include<stdio.h>
#define min -1
void insert(int a[],int n,int size,int ele)
{
    int h;
    h=ele%n;
    int c=0;
    while(c<size)
    {
        if(a[h]==min)
        {
            a[h]=ele;
            return;
        }
        h=(h+1)%size;
        c=c+1;
    }
    if(c==size)
        printf("full\n");
}
void delet(int a[],int n,int size,int ele)
{
    int h,c;
    c=0;
    h=ele%n;
    while(c<size)
    {
        if(a[h]==ele)
        {
            printf("deleted %d",a[h]);
            a[h]=min;
            return;
        }
        c++;
        h=(h+1)%size;
    }
    if(c==size)
        printf("element not found\n");
}
void display(int a[],int n,int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d element at %d tag\n",a[i],i%n);
}
int main()
{
    int a[100];
    int n,size;
    printf("enter size of array\n");
    scanf("%d",&size);
    int i;
    for(i=0;i<size;i++)
        a[i]=min;
    printf("enter mod function\n");
    scanf("%d",&n);
    int ch;
    int ele;
    while(1)
    {
        printf("\n 1:insert 2:delete 3:display 4:exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter the element to insert\n");
            scanf("%d",&ele);
           insert(a,n,size,ele);
        }
        if(ch==2)
        {
            printf("enter element to delete\n");
            scanf("%d",&ele);
           delet(a,n,size,ele);
        }
        if(ch==3)
           display(a,n,size);
        if(ch==4)
            break;
        }
    return 0;
}
