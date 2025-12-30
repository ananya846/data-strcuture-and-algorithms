#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char name[20];
char mobile[10];
struct node *next;
struct node *prev;
};
struct node *head=NULL;

struct node *create(char name[],char mobile[])
{
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
     printf("invalid");
 }
 strcpy(temp->name,name);
 strcpy(temp->mobile,mobile);
 temp->next=NULL;
 temp->prev=NULL;
 return temp;
}
void insert_sort(char name[],char mobile[])
{
    struct node *newnode;
    newnode=create(name,mobile);
    struct node *temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else if(strcmp(name,temp->name)<0)
    {
        newnode->next=temp;
        temp->prev=newnode;
        head=newnode;
    }
    else
    {
        while(temp!=NULL&&((strcmp(name,temp->name)>0)))
              {
                 temp=temp->next;
              }
              if(temp==NULL)
                {
                    struct node *temp1=head;
                    while(temp1->next!=NULL)
                    {
                       temp1=temp1->next;
                    }
                    newnode->prev=temp1;
                       temp1->next=newnode;
                }
              else{newnode->prev=temp->prev;
                 newnode->next=temp;
                 temp->prev->next=newnode;
                 temp->prev=newnode;}
    }
}

void display()
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {   printf("%s %s->",temp->name,temp->mobile);
        temp=temp->next;
    }
   printf("%s %s",temp->name,temp->mobile);

}
int main()
{
    int x;
    char n[20],m[20];
    while(1)
    {
        printf("\nMENU\n1.insert_beg\n2.display\n");
        printf("enter a choice");
        scanf("%d",&x);
        switch(x)
        {
        case 1:printf("enter name and mobile: ");
                scanf("%s%s",n,m);
                insert_sort(n,m);
                break;
        case 2:display();break;
        case 9: exit(0);
        default:printf("invalid choice");
        }
    }
    return 0;
}
