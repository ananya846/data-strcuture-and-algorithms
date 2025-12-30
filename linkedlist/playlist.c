#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char songs[20];
struct node *next;
};
struct node *head;
struct node *create(char song[])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->songs,song);
    temp->next=NULL;
    return temp;
}
void insert_end(char song[])
{
    struct node *newnode;
    newnode=create(song);
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
void display()
{
    if(head==NULL)
    {
        printf("no playlist");
    }
    else
    {   int n;
        printf("enter the number of songs you want to play");
    scanf("%d",&n);
    struct node *temp=head;
        for(int i=0;i<n;i++)
        {
            printf("%s->",temp->songs);
            temp=temp->next;
        }

    }
}
int main()
{
    int n;
    char song[10];
    while(1)
    {
        printf("\nMENU\n1.insert_song\n2.display_song\n3.exit\n");
        printf("enter a choice ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:printf("enter song to be inserted ");
                scanf("%s",song);
                insert_end(song);
                break;
        case 2:display();break;
        case 3: exit(0);
        default:printf("invalid choice");
        }
    }
    return 0;
}
