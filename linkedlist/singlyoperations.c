#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head=NULL;

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

void insert_beg(int value)
{   struct node *newnode;
    newnode=create(value);
    struct node *temp;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }

}
void insert_end(int value)
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

}
void insert_pos(int value,int pos)
{   struct node *newnode;
    newnode=create(value);
        if(pos==1)
        {
            insert_beg(value);
        }
        else
        {
            int c;
            struct node *temp1,*temp2;
            temp1=head;
            for(c=1;c<=pos-1 &&temp1!=NULL;c++)
            {
                temp2=temp1;
                temp1=temp1->next;
            }
         if (c <= pos-1)
        {
            printf("Cannot insert at position %d\n", pos);
            free(newnode);
            return;
        }
            temp2->next=newnode;
            newnode->next=temp1;
        }
    }



void delete_beg()
{
if(head==NULL)
{
    printf("invalid");
}
else {
struct node *temp=head;
head=head->next;
free(temp);}
}

void delete_end()
{
if(head==NULL)
{
    printf("invalid");
}
else {struct node *temp,*temp2;
temp=head;
while(temp->next!=NULL)
{
    temp2=temp;
    temp=temp->next;
}
temp2->next=NULL;
free(temp);}
}
void delete_pos(int pos)
{
if(head==NULL)
{
    printf("invalid");
}
else if(pos==1)
{
 delete_beg();
}
else{struct node *temp1,*temp2;
temp1=head;
for(int i=1;i<=pos-1 && temp1!=NULL;i++)
{
    temp2=temp1;
    temp1=temp1->next;
}
if(temp1==NULL)
{
    printf("out of range");
}
else
{temp2->next=temp1->next;
free(temp1);}}
}
void delete_key(int key)
{
    struct node *temp=head;
if(head==NULL)
{
    printf("invalid");
}
else if(temp!=NULL&&temp->data==key)
{
    head=head->next;
    free(temp);
}
else {
        struct node *temp2;
while(temp!=NULL && temp->data!=key)
{   temp2=temp;
    temp=temp->next;
}
    if(temp==NULL)
    {
    printf("key not found");
    }
    else{
    temp2->next=temp->next;
    free(temp);}
}}

void display()
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
    int n,value,pos,key;
    while(1)
    {
        printf("\nMENU\n1.insert_beg\n2.insert_end\n3.insert_pos\n4.delete_beg\n5.delete_end\n6.delete_pos\n7.delete_val\n8.display\n");
        printf("enter a choice");
        scanf("%d",&n);
        switch(n)
        {
        case 1:printf("enter value to be inserted");
                scanf("%d",&value);
                insert_beg(value);
                break;
        case 2:printf("enter value to be inserted");
                scanf("%d",&value);
                insert_end(value);
                break;
        case 3:printf("enter value to be inserted and the position");
                scanf("%d%d",&value,&pos);
                insert_pos(value,pos);
                break;
        case 4:delete_beg();break;
        case 5:delete_end();break;
        case 6:printf("enter position to be deleted");
                scanf("%d",&pos);
                delete_pos(pos);
                break;
        case 7:printf("enter key to be deleted");
                scanf("%d",&key);
                delete_key(key);
                break;
        case 8:display();break;
        case 9: exit(0);
        default:printf("invalid choice");
        }
    }
    return 0;
}
