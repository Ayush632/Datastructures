#include<stdio.h>
struct stack{
char a[100];
int top;
};
typedef struct stack stack;
void push(stack*s,char e)
{
    s->a[++s->top]=e;
}
char pop(stack*s)
{
    return s->a[s->top--];
}
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
int main()
{
    stack s;
    s.top=-1;
    char infix[100];
    int i,j;
    i=0;
    char buf;
    j=0;
    printf("enter infix expression\n");
    scanf("%s",infix);
    int l;
    l=strlen(infix);
    char postfix[100];
    for(i=0;i<l;i++)
    {
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            push(&s,infix[i]);
        else if(infix[i]==')')
        {
            while(s.a[s.top]!='(')
                postfix[j++]=pop(&s);
            buf=pop(&s);
        }
        else{
            while(s.top!=-1&&check(infix[i],s.a[s.top]))
                postfix[j++]=pop(&s);
            push(&s,infix[i]);
            }
    }
    while(s.top!=-1)
        postfix[j++]=pop(&s);
    printf("\n%s",postfix);
    return 0;
}
