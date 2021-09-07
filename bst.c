#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
void insert(int k,struct node**root) {
    if((*root)==NULL) {
        struct node *temp= (struct node*) malloc(sizeof(struct node));
        (*root)=temp;
        (*root)->left=NULL;
        (*root)->right=NULL;
        (*root)->data=k;
        return;
    }
    if(k<(*root)->data) {
        insert(k,&((*root)->left));
    }
    else if(k>(*root)->data) {
        insert(k,&((*root)->right));
    }
}
void inorder(struct node* root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main() {
    int t=1;
    struct node *root=(struct node*) malloc(sizeof(struct node));
    root->left=NULL;
    root->right=NULL;
    root=NULL;
    while(t) {
        printf("Enter your choice: ");
        int k;
        scanf("%d",&k);
        switch(k) {
            case 1:
                printf("Enter Data to Insert: ");
                int a;
                scanf("%d",&a);
                insert(a,&root);
                break;
            case 2:
                if(root==NULL) {
                    printf("Tree is Empty\n");
                    break;
                }
                inorder(root);
                printf("\n");
                break;
            case 3:
                if(root==NULL) {
                    printf("Tree is Empty\n");
                    break;
                }
                preorder(root);
                printf("\n");
                break;
            case 4:
                if(root==NULL) {
                    printf("Tree is Empty\n");
                    break;
                }
                postorder(root);
                printf("\n");
                break;
            default:
                t=0;
                break;
        }
    }
}