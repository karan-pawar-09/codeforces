#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

Node * GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->right=newNode->left=NULL;
    return newNode;
}

Node* Insert(Node* a, int data) {
    if(a==NULL) {
        a=GetNewNode(data);
    }
    else if(data <= a->data) {
        a->left =Insert(a->left,data);
    }
    else {
        a->right= Insert(a->right,data);
    }
    return a;
}

bool search(Node* root,int data) {
    if(root==NULL) {
        return false;
    }
    else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return search(root->left,data);
	}
	else {
		return search(root->right,data);
    }
}
    int maxDepth(struct Node* node) 
    {
        if (node==NULL) 
            return 0;
        else
        {
             /* compute the depth of each subtree */
              int lDepth = maxDepth(node->left);
              int rDepth = maxDepth(node->right);


                cout<<lDepth<<"  "<<rDepth<<endl;
              /* use the larger one */
              if (lDepth > rDepth) 
                    return(lDepth+1);
              else 
                   return(rDepth+1);
       }
    }

int main() {
    Node* root =NULL;
    root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
    int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	if(search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
    cout<<maxDepth(root);
}


