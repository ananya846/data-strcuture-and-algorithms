#include<stdio.h>
#include<stdlib.h>
#define max 4
int cqueue[max];
int front=-1;
int rear=-1;
void enqueue()
{
   if((front==rear+1)||(front==0 && rear==max-1)) //front==0 is very important here
          {printf("queue is full");
      }
    else
    {   int v;
        printf("enter the element to be inserted");
        scanf("%d",&v);
        if(front==-1)
            {front=0;}
        rear=(rear+1)%max;      //since we are inserting not deleting we dont come accross a situation where rear becomes -1
        cqueue[rear]=v;
    }
}
void dequeue()
{
   if(front==-1)
   {
       printf("queue is empty");
   }
   else
   {   printf("deleted element:%d",cqueue[front]);
        if(front==rear)      //if there is only 1 element then front=(front+1)%max wont make it -1
       {
           front=-1;
           rear=-1;
       }
       else
       {
           front=(front+1)%max;
       }
   }
}
void display()
{
    if(front==-1)
   {
       printf("queue is empty");
   }
   else
   {    int i;
       for(i=front;i!=rear;i=(i+1)%max)
       {
              printf("%d ",cqueue[i]);
       }
        printf("%d ",cqueue[i]);
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
