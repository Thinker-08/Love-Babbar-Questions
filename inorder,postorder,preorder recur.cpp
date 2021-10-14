#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)
struct Tree
{
    int data;
    Tree* left;
    Tree* right;
    Tree(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Tree* head)
{
    if(head==NULL)
    {
        return;
    }
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}
void preorder(Tree* head)
{
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}
void postorder(Tree* head)
{
    if(head==NULL)
        return;
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}
int main()
{
    bb;bb1;
    Tree* head = new Tree(1);
    head->left = new Tree(2);
    head->right = new Tree(3);
    head->right->left = new Tree(8);
    head->left->left = new Tree(4);
    head->left->right = new Tree(5);
    head->right->right = new Tree(6);
    head->right->right->right = new Tree(7);
    cout<<"INORDER: ";
    inorder(head);
    cout<<"\n"<<"PREORDER: ";
    preorder(head);
    cout<<"\n"<<"POSTORDER: ";
    postorder(head);
    return 0;
}