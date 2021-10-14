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
bool isBST(Node* root, Node* min,Node* max)
{
    if(root==NULL)
    {
        return true;
    }
    if(min!=NULL && root->data<=min->data)
    {
        return false;
    } 
    if(max!=NULL && root->data>=max->data)
    {
        return false;
    }
    bool leftvalid = isBST(root->left,min,root);
    bool rightvalid = isBST(root->right,max,root);
    return leftvalid && rightvalid;
}
/*
            1
           / \
          2   3
        


*/            
int main()
{
    bb;bb1;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout<<endl<<isBST(root,NULL,NULL);
    return 0;
}