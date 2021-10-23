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

void inorderDll(Tree* node,Tree* &head,Tree* &prev,int &f)  
{
    if(node==NULL)
    {
        return; 
    }
    inorderDll(node->left,head,prev,f);
    if(f==0)
    {
        f=1;
        head = node;
        prev = node;
    }
    else
    {
        prev->right = node;
        prev->right->left = prev;
        prev = prev->right;
    }
    inorderDll(node->right,head,prev,f);
}
void display(Tree* node)
{
    Tree* temp = node;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}
int main()
{
    bb;bb1;
    Tree* head = new Tree(1);
    head->left = new Tree(2);
    head->right = new Tree(3);
    head->left->left = new Tree(4);
    head->left->right = new Tree(5);
    head->right->left = new Tree(6);
    head->right->right = new Tree(7);
    head->left->right->left = new Tree(8);
    Tree* cur=NULL,* prev=NULL;
    int t=0;
    inorderDll(head,cur,prev,t);
    display(cur);
    return 0;
}