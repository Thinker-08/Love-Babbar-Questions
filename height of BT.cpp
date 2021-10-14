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
int height(Tree* head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        int l = height(head->left);
        int r = height(head->right);
        if(l>r)
        {
            return(l+1);
        }
        else
        {
            return (r+1);
        }
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
    int a;
    a = height(head)-1;
    cout<<a;
    return 0;
}