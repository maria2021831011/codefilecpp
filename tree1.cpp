
#include<bits/stdc++.h>
using namespace std;

struct node{
 int data;
 struct node *left;
 struct node *right;
};


struct node *create()
{
    int x;
    cout<<"Enter the inserting data(-1for no data.):";
    cin>>x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(x==-1)
    return 0;
    newnode->data=x;
    cout<<"Enter the left child of : "<<x;
    newnode->left=create();
   cout<<"Enter the right child of : "<<x;
    newnode->right=create();

    return newnode;



}
void preorder (struct node *root)
{

   if(root==0)
   {
    return;
   }
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}
void inorder (struct node *root)
{

   if(root==0)
   {
    return;
   }

   inorder(root->left);
    cout<<root->data<<" ";
   inorder(root->right);
}
void postorder (struct node *root)
{

   if(root==0)
   {
    return;
   }

   postorder(root->left);
   postorder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    struct node *root;
    root=0;
    root=create();
    preorder(root);

    return 0;
}
