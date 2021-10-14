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

int diameter(Tree* node,int* hei)
{
    int lh = 0,rh = 0,ldiameter=0,rdiameter=0;
    if(node==NULL)
    {
        *hei = 0;
        return 0;
    }
    ldiameter = diameter(node->left,&lh);
    rdiameter = diameter(node->right,&rh);
    *hei = max(lh,rh)+1;
    return max(lh+rh,max(ldiameter,rdiameter));
}

int main()
{
    bb;bb1;
    Tree* head = new Tree(1);
    head->left = new Tree(2);
    head->right = new Tree(3);
    head->left->left = new Tree(4);
    head->left->right = new Tree(5);
    head->right->right = new Tree(6);
    head->right->right->right = new Tree(7);
    int a;
    int hei = 0;
    a = diameter(head,&hei);
    cout<<a;
    return 0;
}