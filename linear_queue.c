#include<stdio.h>
#include<stdlib.h>
#define max 3
int queue[max];
int front=-1;
int rear=-1;
void enqueue()
{
    if(rear==max-1)
    {
        printf("queue is full\n");
    }
    else
    {
        if(front==-1)
            front=0;
            int v;
        printf("enter the element to be inserted");
        scanf("%d",&v);
        rear=rear+1;
        queue[rear]=v;
    }

}
void dequeue()
{
    if(front==-1||front>rear)//either the queue is just empty or u kept popping elements so front>rear
    {
        printf("empty queue\n");
    }
    else
    {
        printf("deleted element:%d",queue[front]);
        front=front+1;
    }
}
void display()
{
   if(front==-1||front>rear)//either the queue is just empty or u kept popping elements so front>rear
    {
        printf("empty queue\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}
int main()
{   int choice,v;
    while(1)
    {
        printf("\nMenu\n1.enqueue\n2.dequeue\n3.display\n4.exit");
        printf("\nenter choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:enqueue();break;
        case 2:dequeue();break;
        case 3:display();break;
        case 4:exit(0);
        default:printf("ivalid choice");

        }
    }
    return 0;
}
