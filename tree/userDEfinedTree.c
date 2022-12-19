#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node* MakeNode(int x)
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
CreateTree(struct node **T)
{
    struct node *p;
    int choice,x;
    printf("whether the left exist of %d?(1/0)",(*T)->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("input the data of left node of %d",(*T)->data);
        scanf("%d",&x);
        p=MakeNode(x);
        (*T)->left=p;
        CreateTree(&p);
    }
    printf("whether the right exist of %d?(1/0)",(*T)->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("input the data of right node of %d",(*T)->data);
        scanf("%d",&x);
        p=MakeNode(x);
        (*T)->right=p;
        CreateTree(&p);
    }
}
void PreOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        printf("%d ",T->data);
        PreOrderTraversal(T->left);
        PreOrderTraversal(T->right);
    }
}
void InOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        InOrderTraversal(T->left);
        printf("%d ",T->data);
        InOrderTraversal(T->right);
    }
}
void PostOrderTraversal(struct node *T)
{
    if(T!=NULL)
    {
        PostOrderTraversal(T->left);
        PostOrderTraversal(T->right);
        printf("%d ",T->data);
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
    int x;
    struct node *root=NULL;
    printf("enter the data of root node");
    scanf("%d",&x);
    root=MakeNode(x);
    CreateTree(&root);
    printf("pre order traversal =>\n");
    PreOrderTraversal(root);
    printf("In order traversal =>\n");
    InOrderTraversal(root);
    printf("post order traversal =>\n");
    PostOrderTraversal(root);
    int b=countNode(root);
    printf("\n no. of nodes=>%d",b);
    int y=countLeafNode(root);
    printf("\n no. of leaf nodes=>%d",y);
    int z=countN1(root);
    printf("\n no. of nodes with 1 child=>%d",z);
    int a=countN2(root);
    printf("\n no. of nodes with 2 child=>%d",a);
    int h=height(root);
    printf("\n height of tree=>%d",h);
    return 0;
    if(IsStrictly)
    printf("yes");
    else
    printf("no");
}