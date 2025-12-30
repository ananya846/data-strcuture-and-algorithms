#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int roll;
    char name[20];
    int marks;
    struct node *next;
};
struct node *create(int r,char n[],int m)
{
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
     printf("invalid");
 }
 temp->roll=r;
 strcpy(temp->name,n);
 temp->next=NULL;
 temp->marks=m;
 return temp;
}
struct node *insert_end(struct node *head,int r,char n[],int m)
{   struct node *newnode;
    newnode=create(r,n,m);
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
void display(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {   printf("%d %s %d-> ",temp->roll,temp->name,temp->marks);
        temp=temp->next;
    }
        printf("%d %s %d ",temp->roll,temp->name,temp->marks);

}
void display_lists(struct node *head)
{
    struct node *temp=head;
    struct node *pass=NULL;
    struct node *fail=NULL;
    while(temp!=NULL)
    {
        if(temp->marks>=40)
        {
            pass=insert_end(pass,temp->roll,temp->name,temp->marks);
        }
        else
        {
            fail=insert_end(fail,temp->roll,temp->name,temp->marks);
        }
        temp=temp->next;
    }
    printf("DISPLAY PASS STUDENTS:");
    display(pass);
    printf("Display fail students:");
    display(fail);
}

int main()
{   struct node *head=NULL;
    int x,r,m;
    char n[20];
    printf("enter the number of students:");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        printf("enter the name, roll and totals marks of student %d",i+1);
        scanf("%s %d %d",n,&r,&m);
        head=insert_end(head,r,n,m);
    }
    display_lists(head);
    return 0;
}
