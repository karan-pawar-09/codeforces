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
void deleteNode(struct Node *t,int pos) {
    struct Node *q,*p;
    if(pos==1) {
        q = t;
        t = t->next;
        free(q);
    }
    else {
        p=t;
        q=NULL;
        for(int i=0;i<pos-1;i++) {
            q = p;
            p = p->next;
        }
        q->next=p->next;
        free(p);        
    }
}

int main() {
    int array[]={1,2,3,4,5,6};
    create(array,6);
    deleteNode(head,3);
    printLinkedList(head);    
}