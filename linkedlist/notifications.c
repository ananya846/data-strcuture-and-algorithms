#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char msg[50];
    struct node *next;
};
struct node *head=NULL;
struct node *create(char m[])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->msg,m);
    temp->next=NULL;
    return temp;
}
void insert_end(char m[])
{
    struct node *newnode;
    newnode=create(m);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
          temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;

    }

}
void delete_beg()
{

if(head==NULL)
{
    printf("deletion not possible");
}
struct node *del=head;
if(head->next==head)
{
    head=NULL;

}
else{
struct node *temp=head;
while(temp->next!=head)
{
   temp=temp->next;
}
head=head->next;
temp->next=head;
free(del);
}
}
void display()
{
    if(head==NULL)
    {
        printf("no notifications");
    }
    else
    {   int n;
        printf("enter the number of notification u want to see");
        scanf("%d",&n);struct node *temp=head;
        for(int i=0;i<n;i++)
        {
            printf("%s ->",temp->msg);
            temp=temp->next;
        }
        printf("%s",temp->msg);
    }
}
int main()
{
    char m[20];
    int n;
    while(1)
    {
        printf("\nMENU\n1.insert_end\n2.delete_beg\n3.display\n");
        printf("\nenter a choice");
        scanf("%d",&n);
        switch(n)
        {
        case 1:printf("\nenter value to be inserted");
                scanf("%s",m);
                insert_end(m);
                break;
        case 2:delete_beg();break;
        case 3:display();break;
        case 4: exit(0);
        default:printf("invalid choice");
        }
    }
    return 0;
}
