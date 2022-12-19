#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* Makenode(int x)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
BSTInsert(struct node **T,int x)
{
    struct node *p,*q;
    p=*T;
    q=NULL;
    if(*T==NULL)
    *T=Makenode(x);
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(x<p->data)
            p=p->left;
            else
            p=p->right;
        }
        if(x<q->data)
        q->left=Makenode(x);
        else
        q->right=Makenode(x);
    }
}
InOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        InOrderTraversal(T->left);
        printf(" %d",T->data);
        InOrderTraversal(T->right);
    }
}
int main()
{
    struct node *root=NULL;
    BSTInsert(&root,100);
    BSTInsert(&root,50);
    BSTInsert(&root,70);
    BSTInsert(&root,130);
    BSTInsert(&root,150);
    BSTInsert(&root,20);
    BSTInsert(&root,40);
    InOrderTraversal(root);
}