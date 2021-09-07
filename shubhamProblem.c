#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
}*head=NULL;

void create(int a[],int n)
{
    struct node *t,*last ;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = a[0];
    head->next = NULL;
    last = head;
    for(int i=1;i<n;i++)
    {
        t = (struct node*) malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert_at_front(struct node *p,int dom)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data = dom;
    t->next = head;
    head = t;
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    int a[5]= {1,2,3,4,5};
    create(a,5);
    display(head);
    insert_at_front(head,10);
    printf("\n");
    display(head);
    return 0;
}