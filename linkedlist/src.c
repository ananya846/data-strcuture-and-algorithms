#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};

struct node *create(int value)
{
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
     printf("invalid");
 }
 temp->data=value;
 temp->next=NULL;
 return temp;
}
struct node *insert_end(struct node *head,int value)
{   struct node *newnode;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }
    return head;
}

struct node *sort(struct node *head)
{
  struct node *i=NULL,*j=NULL;
  i=head;
  while(i!=NULL)
  {
      j=i->next;
      while(j!=NULL)
      {
          if(i->data>j->data)
          {
              int temp;
              temp=i->data;
              i->data=j->data;
              j->data=temp;
          }
          j=j->next;
      }
      i=i->next;
  }
  return head;
}
struct node *concate(struct node *head1,struct node *head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    else
    {
        struct node *temp=head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head2;
        return head1;
    }
}
struct node *reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *current=head;
    struct node *upnext=NULL;
    while(current!=NULL)
    {
        upnext=current->next;
        current->next=prev;
        prev=current;
        current=upnext;//imp
    }
    return prev;//now the head the last node
}

void display(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {   printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);

}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    int val;
    for(int i=0;i<3;i++)
    {
        printf("enter the value to be inserted into first linkedlist:\n");
        scanf("%d",&val);
        head1=insert_end(head1,val);
    }
    for(int i=0;i<4;i++)
    {
        printf("enter the value to be inserted into second linkedlist:\n");
        scanf("%d",&val);
        head2=insert_end(head2,val);
    }
    printf("first linkedlist:");
    display(head1);
     printf("\nsecond linkedlist:");
    display(head2);

printf("\nsorted first linkedlist:");
head1=sort(head1);
display(head1);

printf("\nreversed second linkedlist");
head2=reverse(head2);
display(head2);

printf("\nconcatenting both linked list:");
struct node *concatenated=concate(head1,head2);
display(concatenated);

    return 0;
}
