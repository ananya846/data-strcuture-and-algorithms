#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top=-1;
void push(int x)
{
    if(top==(max-1))
    {
        printf("overflow");
    }
    else
    {
        top=top+1;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else
    {
    int ele=stack[top];
    top=top-1;
    printf("element popped:%d",ele);
    }
}
void peek()
{
  if(top==-1)
    {
        printf("underflow");
    }
    else{printf("element peeked:%d",stack[top]);}
}
void display()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else{
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int choice,val;
    while(1){
    printf("\nMENU\n1.push\n2.pop\n3.peek\n4.display\n");
    printf("enter the choice");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("enter the value to be pushed:");
    scanf("%d",&val);
    push(val);break;
    case 2:pop();break;
    case 3:peek();break;
    case 4:display();break;
    default:printf("invalid choice");
    }}
    return 0;
}

