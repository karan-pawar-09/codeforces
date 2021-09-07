#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int data;
    Node *next;
}p;
void create(arr[],n) {
    p->data=arr[0];
    for(int i=1;i<n;i++) {
        Node *temp;
        temp=new Node;
        p->next=temp;
        p->data=arr[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}