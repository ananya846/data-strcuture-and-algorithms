#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
int stack[max];
int top=-1;
void push(char ch)
{
    if(top==(max-1))
    {
        printf("overflow");
    }
    else
    {
        top=top+1;
        stack[top]=ch;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else{
    int ele=stack[top];
    top=top-1;
    return ele;
    }
}
int main()
{
    char s[20];
    printf("enter a string:");
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        push(s[i]);
    }
    int i;
    for( i=0;i<strlen(s);i++)
    {
        s[i]=pop();
    }
    s[i]='\0';
    printf("reversed string: %s",s);
    return 0;
}

