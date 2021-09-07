#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    Node *next;
};
void create(int arr[],int n,Node** first) {
    Node *t,*l;
    (*first)=(Node*)malloc(sizeof(Node));
    (*first)->data=arr[0];
    (*first)->next=NULL;
    l=*(first);
    for(int i=1;i<n;i++) {
        t=(Node*)malloc(sizeof(Node));
        t->data=arr[i];
        t->next=NULL;
        l->next=t;
        l=t;
    }
}
void display (Node *p) {
    if(p!=NULL) {
        printf("%d",p->data);
        display(p->next);        
    }
}
int no (Node *p) {
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
int max(Node *p) {
    int x=INT_MIN;
    if(p==NULL)
        return INT_MIN;
    x=max(p->next);
    if(x<=p->data)
        x=p->data;
    return x;
}
void insert(Node *p,int index,int nom,Node *first) {
    if(index<0||index> no(p)) {
        return;
    }
    Node *t=(Node *)malloc(sizeof(Node));
    t->data=nom;
    if(index==0) {
        t->next=first;
        first=t;
    }
    else {
        for(int i=0;i<index-1;i++) {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
void sortedInsert(Node *p,int x,Node *first) {
    Node *t=(Node*)malloc(sizeof(Node));
    t->data=x;
    t->next=NULL;
    Node *q=NULL;
    if(first==NULL) {
        first=t;
    }
    else{
        while(p&&p->data<x) {
            q=p;
            p=p->next;
        }
        if(p==first) {
                t->next=first;
                first=t;
            }
        else{
            t->next=q->next;
            q->next=t;
       }
    }

}
void createByInsert(Node *p,int arr[],int size,Node *first) {
    insert(first,0,arr[0],first);
    for(int i=1;i<size;i++) {
        insert(first,i,arr[i],first);
    }
}
int main() {
    int arr[]={1,3,6,8,9};
    struct Node* first=NULL;
    create(arr,5,&first);    
    sortedInsert(first,5,first);
    sortedInsert(first,6,first);
    display(first); 
    return 0;
}