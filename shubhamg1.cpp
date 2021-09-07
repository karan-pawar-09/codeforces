/*
author:Karan
created:07.07.2021 15:13:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

class Node{     
public:
    ll val;
    ll count;
    Node* left;
    Node* right;
    Node(ll num1, ll num2) {
        this->val = num1;
        this->count = num2;
        this->left = this->right = NULL;
    }
};

ll addNode(Node*& root, ll value, ll countSmaller) {
    if (root == NULL) {
        root = new Node(value, 0);
        return countSmaller;
    }
    if (root->val < value)  {
        return root->count + addNode(root->right,value,countSmaller + 1);
    }
    else {
        root->count++;
        return addNode(root->left, value, countSmaller);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    Node *root=NULL;
    ll total=0;
    for(ll i=n-1;i>=0;i--) {
        total+=addNode(root,arr[i],0);
    }
    cout<<total<<endl;
} 