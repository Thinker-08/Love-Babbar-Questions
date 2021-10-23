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
bool path(Tree* node,int n,vector<int> &v)
{
    if(node==NULL)
        return false;
    v.push_back(node->data);
    if(node->data==n)
    {
        return true;
    }
    if(path(node->left,n,v) || path(node->right,n,v))
        return true;

    v.pop_back();   
    return false;
}
int fun(Tree* head, int n1, int n2)
{
    vector<int> v1,v2;
    if(!path(head,n1,v1) || !path(head,n2,v2))
    {
        return -1;
    }
    int i=0;
    for(i=0;i<v1.size();i++)
    {
        if(v1[i]!=v2[i])
            break;
    }
    return v1[i-1];
}
Tree* fun1(Tree* node,int n1,int n2)
{
    if(node==NULL)
        return NULL;
    if(node->data==n1 || node->data==n2)
        return node;
    Tree* l = fun1(node->left,n1,n2);
    Tree* r = fun1(node->right,n1,n2);
    if(l!=NULL &&  r!=NULL)
        return node;
    if(l!=NULL)
        return fun1(node->left,n1,n2);
    return fun1(node->right,n1,n2);
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
    int n1,n2;
    cin>>n1>>n2;
    int a = fun(head,n1,n2);
    cout<<"Using unoptimize Code: "<<a;
    Tree* b = fun1(head,n1,n2);
    cout<<"\nUsing optimized Code:  "<<b->data;
    return 0;
}