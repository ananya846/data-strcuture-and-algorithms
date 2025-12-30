#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;
struct node *create(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
void insert_beg(int value)
{
    struct node *newnode;
    newnode=create(value);
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
        newnode->next=head;
            head=newnode;
            temp->next=newnode;
    }
}
void insert_end(int value)
{
    struct node *newnode;
    newnode=create(value);
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
void insert_pos(int value,int pos)
{
    struct node *newnode;
    newnode=create(value);
        if(pos==1)
        {
           insert_beg(value);
        }
     else{   struct node *temp1,*temp2;
        temp1=head;
       for(int i=1;i<=pos-1;i++)
       {
           temp2=temp1;
           temp1=temp1->next;
       }
       if(temp1==head)
       {
           temp2->next=newnode;
        newnode->next=head;
       }
       else{
         temp2->next=newnode;
        newnode->next=temp1;
       }

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

void delete_end()
{
if(head==NULL)
{
    printf("deletion not possible");
}
struct node *temp=head;
struct node *temp2;
if(head->next==head)
{
    head=NULL;
}
else{while(temp->next!=head)
{   temp2=temp;
    temp=temp->next;
}
temp2->next=head;
free(temp);
}
}

void delete_pos(int pos)
{
if(head==NULL)
{
    printf("deletion not possible");
}
if(pos==1)
{
    delete_beg();
}
else{
        struct node *temp1,*temp2;
        temp1=head;
    for(int i=1;i<=pos-1;i++)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    if(temp1==head)
    {
        printf("out of range");
    }
    else if(temp1->next==head)
    {
        temp2->next=head;
        free(temp1);
    }
    else{
        temp2->next=temp1->next;
        free(temp1);
    }
}

}
void delete_key(int key)
{
if(head==NULL)
{
    printf("deletion not possible");
}
struct node *temp=head;
if(head->data==key && head->next==head)
{
    head=NULL;
}
else{
        struct node *temp1,*temp2;
        temp1=head;
    while(temp1->data!=key && temp1!=NULL)
    {   temp2=temp;
        temp1=temp1->next;
    }


        if(temp1->next==head)
        {
           temp2->next=head;
        free(temp1);
        }
        else{
            temp2->next=temp1->next;
             free(temp1);
        }

}
}
void display()
{
    if(head==NULL)
    {
        printf("no linkedlist");
    }
    else
    {   struct node *temp=head;
        while(temp->next!=head)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
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
