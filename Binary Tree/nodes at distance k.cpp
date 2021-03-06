#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
using namespace std;
struct Node
{
    int data;
    Node* left; 
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void printsubtreenodes(Node* root,int k)
{
    if(root==NULL || k<0)
        return ;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}
int printnodesatk(Node* root,Node* target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        printsubtreenodes(root,k);
        return 0;
    }
    int dl = printnodesatk(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printsubtreenodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr = printnodesatk(root->right,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printsubtreenodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
/*
            1
           / \
          2   3
         / \ / \
        4  56   7
       / \     / \
      8   9   10 11


*/            
int main()
{
    bb;bb1;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);
    printnodesatk(root,root->left->left,5);
    return 0;
}