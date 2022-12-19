#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
    char data;
    struct node *right;
    struct node *left;
};
struct node* MakeNode(char x)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void PreOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        printf("%c ",T->data);
        PreOrderTraversal(T->left);
        PreOrderTraversal(T->right);
    }
}
void InOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        InOrderTraversal(T->left);
        printf("%c ",T->data);
        InOrderTraversal(T->right);
    }
}
void PostOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        PostOrderTraversal(T->left);
        PostOrderTraversal(T->right);
        printf("%c ",T->data);
    }
}
int countNode(struct node *T)
{
    if(T==NULL)
    return 0;
    else
    return 1+countNode(T->left)+countNode(T->right);
}
int countLeafNode(struct node *T)
{
    if(T==NULL)
    return 0;
    else 
    {
    if(T->left==NULL && T->right==NULL)
    return 1;
    else
    return countLeafNode(T->left)+countLeafNode(T->right);
    }
}
int countN2(struct node *T)
{
    if(T==NULL)
    return 0;
    else
    {
    if(T->left==NULL && T->right==NULL)
    return 0;
    else
    {
        if(T->left!=NULL && T->right!=NULL)
        return 1+countN2(T->left)+countN2(T->right);
        else
        return countN2(T->left)+countN2(T->right);
    }
    }
}
int countN1(struct node *T)
{
    if(T==NULL)
    return 0;
    else
    {
    if(T->left==NULL && T->right==NULL)
    return 0;
    else
    {
        if(T->left!=NULL && T->right!=NULL)
        return countN1(T->left)+countN1(T->right);
        else
        return 1+countN1(T->left)+countN1(T->right);
    }
    }
}
int height(struct node *T)
{
    if(T==NULL)
    return 0;
    else
    {
    if(T->left==NULL && T->right==NULL)
    return 0;
    else
    return max(height(T->left),height(T->right))+1;
    }
}
IsStrictly(struct node *T)
{
    if(countN1(T)==0)
    return TRUE;
    else 
    return FALSE;
}
int main()
{
    struct node *root=NULL;
    root=MakeNode('A');
    root->left=MakeNode('B');
    root->right=MakeNode('C');
    root->left->left=MakeNode('F');
    root->right->left=MakeNode('D');
    root->right->right=MakeNode('E');
    printf("\npre order traversal =>");
    PreOrderTraversal(root);
    printf("\nIn order traversal =>");
    InOrderTraversal(root);
    printf("\npost order traversal =>");
    PostOrderTraversal(root);
    int x=countNode(root);
    printf("\n%d",x);
    int y=countLeafNode(root);
    printf("\n%d",y);
    int z=countN1(root);
    printf("\n%d",z);
    int a=countN2(root);
    printf("\n%d",a);
    int h=height(root);
    printf("\n%d",h);
    if(IsStrictly)
    printf("yes");
    else
    printf("no");
}
