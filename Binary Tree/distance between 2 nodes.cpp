#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
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
int distance(Tree* head,int dis,int n)
{
    if(head==NULL)
        return 0;
    if(head->data==n)
    {
        return dis;
    }
    dis = dis+1;
    if(head->left!=NULL)
        if(distance(head->left,dis,n)==0)
            return distance(head->right,dis,n);
        else
            return distance(head->left,dis,n);
    else
        return distance(head->right,dis,n);
}
Tree* find_LCA(Tree* head,int n1,int n2)
{
    if(head==NULL)
        return NULL;
    if(head->data==n1 || head->data==n2)
    {
        return head;
    }
    Tree* l = find_LCA(head->left,n1,n2);
    Tree* r = find_LCA(head->right,n1,n2);
    if(l!=NULL && r!=NULL)
        return head;
    if(l==NULL && r==NULL)
        return NULL;
    if(l!=NULL)
    {
        return find_LCA(head->left,n1,n2);
    }
    return find_LCA(head->right,n1,n2);
}
int driver(Tree* head,int n1, int n2)
{
    Tree* lca = find_LCA(head,n1,n2);
    int l=0,r=0;
    l = distance(lca,l,n1);
    r = distance(lca,r,n2);
    return l+r;
}
int main()
{
    bb;bb1;
    Tree* head1 = new Tree(1);
    head1->left = new Tree(2);
    head1->right = new Tree(3);
    head1->left->left = new Tree(4);
    head1->left->right = new Tree(5);
    head1->right->left = new Tree(6);
    head1->right->right = new Tree(7);
    head1->right->right->right = new Tree(8);
    head1->right->right->left = new Tree(9);
    head1->left->left->left = new Tree(10);
    int n1,n2;
    cin>>n1>>n2;
    int sum = driver(head1,n1,n2);
    cout<<sum;
    return 0;
}