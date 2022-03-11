/*
    author:Karan
    created:05.03.2022 14:06:05
*/
#include<stdio.h> 
#include<stdlib.h>
#include <string>
#include<cstring>

char str[1024];
int power(int a, int b) {
    int res=1;
    for(int i=0;i<b;i++) {
        res*=a;
    }
    return res;
}
int strtoint() {
    int ans=0;
    for(int i=0;i<6;i++) {
        ans+=(str[i]-'0')*power(10,5-i);
    }
    return ans;
}
struct Node {
    int key;
    char details[1024];
    Node *next;
};
struct Node *head = NULL;
struct node *current = NULL;
void printList() {
   struct Node *ptr = head;
   while(ptr != NULL) {
      printf("%d %s\n",ptr->key,ptr->details);
      ptr = ptr->next;
   }
}

void insertFirst() {
   struct Node *link = (struct Node*) malloc(sizeof(struct Node));	
   link->key= strtoint();
   strcpy(link->details, str);
   link->next = head;
   head = link;
}

struct Node* deleteFirst() {
   struct Node *tempLink = head;
   head = head->next;
   return tempLink;
}
bool isEmpty() {
   return head == NULL;
}

struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

int main() {
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev=NULL;
    int i=0,j=0;
    FILE* fp;
    fp = fopen("input.txt", "r");
    while (fgets(str,150, fp)) {
        i++;
        insertFirst();
        j++;
    }
    printList();
    fclose(fp);
    return 0;
}