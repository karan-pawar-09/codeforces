#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

// void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& cout) {
//     while (node) {
//         cout << node->data;

//         node = node->next;

//         if (node) {
//             cout << sep;
//         }
//     }
// }

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void insertNodeAtTail(SinglyLinkedListNode** head, int data) {
    SinglyLinkedListNode *t=new SinglyLinkedListNode(data);
    t->data=data;
    t->next=NULL;
	if(*head==NULL) {
        *head=t;
    }
    else{
        SinglyLinkedListNode* p;
        p=*head;
        while(p->next!=NULL) {
            p=p->next;
        }
        p->next=t;
    }

}

int main()
{
 

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    	insertNodeAtTail(&llist->head, llist_item);
    }


    // print_singly_linked_list(llist->head, "\n", cout);
    // cout << "\n";
    while(llist->head) {
        cout<<llist->head->data<<endl;
        llist->head=llist->head->next;
    }

    // free_singly_linked_list(llist->head);


    return 0;
}