#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
struct node *next;
};
struct node *create(int c,int e)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=c;
    temp->exp=e;
    temp->next=NULL;
    return temp;
}
struct node *insert(struct node *p,int c,int e)
{
    struct node *newnode;
    newnode=create(c,e);
    if(p==NULL)
    {
        p=newnode;
    }
    else{
        struct node *temp;
        temp=p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return p;
}
struct node *add(struct node *p1,struct node *p2)
{
    struct node *result=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->exp>p2->exp)
        {
            result=insert(result,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else if(p1->exp<p2->exp)
        {
            result=insert(result,p2->coeff,p2->exp);
            p2=p2->next;
        }
        else
        {
            int sum=p1->coeff+p2->coeff;
            result=insert(result,sum,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1!=NULL)
    {
       result=insert(result,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
         result=insert(result,p2->coeff,p2->exp);
            p2=p2->next;
    }
    return result;
}
void display(struct node *p)
{
    if(p==NULL)
    {
        printf("no polynomial");
    }
    else
    {
        struct node *temp;
        temp=p;
        while(temp->next!=NULL)
        {
            printf("%dx^%d+",temp->coeff,temp->exp);
            temp=temp->next;
        }
        printf("%dx^%d",temp->coeff,temp->exp);
    }
}
int main(){
    int n,m,a,b;
    struct node *p1=NULL,*p2=NULL,*sum=NULL;
    printf("enter the number of terms in the two polynomials");
    scanf("%d%d",&n,&m);
    printf("enter the terms of polynomials 1");
    for(int i=0;i<n;i++)
    {
        printf("\nterm %d coeff and exp=",i+1);
        scanf("%d%d",&a,&b);
        p1=insert(p1,a,b);
    }
    printf("enter the terms of polynomials 2");
    for(int i=0;i<m;i++)
    {
        printf("\nterm %d coeff and exp=",i+1);
        scanf("%d%d",&a,&b);
        p2=insert(p2,a,b);
    }
    sum=add(p1,p2);

    printf("polynomial 1");
    display(p1);

    printf("\npolynomial 2");
    display(p2);

    printf("sum:");
    display(sum);

    return 0;
}
