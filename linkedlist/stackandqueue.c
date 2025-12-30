#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *stack=NULL;
struct node *front=NULL;
struct node *rear=NULL;
void push(struct node *head,int x)
{
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=stack;
stack=newnode;
}
void pop(struct node *head)
{
if(stack==NULL)
{
    printf("stack is empty");
}
else
{
    struct node *temp=stack;
    printf("deleted element:%d",temp->data);
    stack=stack->next;
    free(temp);
}
}
void peek(struct node *head)
{
if(stack==NULL)
{
    printf("stack is empty");
}
else
{
    printf("top element:%d",stack->data);
}
}
void displaystack(struct node *head)
{
if(stack==NULL)
{
    printf("stack is empty");
}
else
{
    struct node *temp=stack;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
}
void enqueue(struct node *head,int x)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=NULL;
if(front==NULL)
{
    front=newnode;
    rear=newnode;
}
else
{
    rear->next=newnode;
    rear=rear->next;
}
}
void dequeue(struct node *head)
{
if(front==NULL)
{
    printf("queue is empty");
}
else
{
    struct node *temp=front;
    printf("deleted element=%d",temp->data);
    front=front->next;
    if(front==NULL)
    {rear=NULL;}
    free(temp);
}
}
void displayqueue(struct node *head)
{
if(front==NULL)
{
    printf("queue is empty");
}
else
{
    struct node *temp=front;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
}
int main()
{   int choice,value;
struct node *head1,*head2;
    while(1){
    printf("\nMenu\n1.push\n2.pop\n3.peek\n4.displaystack\n5.enqueue\n6.dequeue\n7.displayqueue\n8.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("enter the value to be pushed");scanf("%d",&value);
    push(head1,value);break;
    case 2:pop(head1);break;
    case 3:peek(head1);break;
    case 4:displaystack(head1);break;
    case 5:printf("enter the value to be pushed into queue");scanf("%d",&value);
    enqueue(head2,value);break;
    case 6:dequeue(head2);break;
    case 7:displayqueue(head2);break;
    case 8:exit(0);
    default :

    }

    }
}
