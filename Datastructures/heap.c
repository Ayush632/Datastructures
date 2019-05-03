#include<stdio.h>
int n;
int a[100];
void heapify()
{
    int i;

    for(i=n/2;i>0;i--)
        buildheap(i);
}
void buildheap(int i)
{

    int left,right,largest,temp;
    left=2*i;
    right=left+1;
    largest=i;
    if(left<=n&&a[left]>a[largest])
        largest=left;
    if(right<=n&&a[right]>a[largest])
        largest=right;

    if(largest!=i)
    {

        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        buildheap(largest);
    }
}
int extractmax()
{
    if(n<=0)
        printf("empty");
    int max;
    max=a[1];
    a[1]=a[n];
    n=n-1;
    buildheap(1);
    return max;
}
void display()
{
    int i;
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int max,i;
    int ch;

    while(1)
    {
        printf("\n 1:create 2:delete 3:display 4:exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter no of elements\n");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("enter the element\n");
                scanf("%d",&a[i]);
            }

            heapify();
        }
        if(ch==2)
        {
            max=extractmax();
            printf("%d is deleted",max);
        }
        if(ch==3)
            display();
        if(ch==4)
            break;
        }
    return 0;
}
