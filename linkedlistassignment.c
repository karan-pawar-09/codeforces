#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*head=NULL;

void create(int arr[],int n) {
    struct Node *q,*p;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=NULL;
    p=head;
    for(int i=1;i<n;i++) {
        q=(struct Node*)malloc(sizeof(struct Node));
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=q;
    }
}

void printLinkedList (struct Node *p) {
    if(p!=NULL) {
        printf("%d",p->data);
        printLinkedList(p->next);        
    }
}

void insert (struct Node *p, int pos, int given_data) {
    struct Node *t= (struct Node*)malloc(sizeof(struct Node));
    t->data=given_data;
    t->next=NULL;
    if(pos==0) {
        t->next=head;
        head=t;
    }
    else {
        for(int i=0;i<pos-1;i++) {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int main() {
    int array[]={1};
    create(array,1);
    insert(head,0,8);
    printLinkedList(head);    
}