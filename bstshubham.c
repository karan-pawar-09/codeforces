#include<stdio.h>
#include<stdlib.h>
struct nd
{
    int d;
    struct nd* lt;
    struct nd* rt;
};
struct nd* crtNd(int d)
{
    struct nd* temp= (struct nd*)malloc(sizeof(struct nd));
    temp->d = d;
    temp->lt=NULL;
    temp->rt= NULL;
    return temp;
}
struct nd* insert(int d,struct nd* node)
{
    if(node==NULL)
        return crtNd(d);
    else if(d<=node->d)
        node->lt = insert(d,node->lt);
    else
        node->rt = insert(d,node->rt);
    return node;
}
void pro(struct nd* root)
{
    if(root==NULL)   return;
    printf("%d ",root->d);
    pro(root->lt);
    pro(root->rt);
}
void ino(struct nd* root)
{
    if(root==NULL)   return;
    ino(root->lt);
    printf("%d ",root->d);
    ino(root->rt);
}
void poo(struct nd* root)
{
    if(root==NULL)   return;
    poo(root->lt);
    poo(root->rt);
    printf("%d ",root->d);
}

int main()
{
    struct nd* root=NULL;
    while(1)
    {
        int ch,d;
        printf("enter your choice: ");
        scanf("%d",&ch);
        printf("\n");
        if(ch==5)    break;
        switch(ch)
        {
            case 1: printf("enter data: ");
                    scanf("%d",&d);
                    root=insert(d,root);
                    printf("\n");
                    break;
            case 2: if(root==NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        ino(root);
                        printf("\n");
                    }
                    printf("\n");
                    break;
            case 3: if(root==NULL)    printf("Tree is empty\n");
                    else
                    {
                        pro(root);
                        printf("\n");
                    }
                    printf("\n");
                    break;
            case 4: if(root==NULL)    printf("Tree is empty\n");
                    else
                    {
                        poo(root);
                        printf("\n");
                    }
                    printf("\n");
                    break;
        }
    }
    return 0;
}