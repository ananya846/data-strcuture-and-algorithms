#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char name[20];
char mobile[10];
struct node *next;
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
 return temp;
}
void insert_end(char name[],char mobile[])
{   struct node *newnode;
    newnode=create(name,mobile);
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

}
void removeduplicates()
{
    struct node *current=NULL,*follow=NULL,*check=NULL;
    current=head;
    while(current!=NULL)
    {
        follow=current;
        check=current->next;
        while(check!=NULL)
        {
            if(strcmp(current->mobile,check->mobile)==0)
            {
                follow->next=check->next;
                free(check);            //
                check=follow->next;     //
            }
            else
            {
                follow=check;
                check=check->next;
            }
        }
        current=current->next;
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
    printf("\n");

}
int main()
{
    char name[20],mobile[10];
    int n;
    printf("enter the number of customers:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nenter name of cust %d: ",(i+1));
        scanf("%s",name);
        printf("enter mobile of cust %d: ",(i+1));
        scanf("%s",mobile);
        insert_end(name,mobile);
    }
    display();
    removeduplicates();
    display();
    return 0;
}
