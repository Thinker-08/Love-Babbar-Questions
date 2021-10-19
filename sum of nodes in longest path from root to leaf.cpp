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
void fun(Tree* head,int* sum,int* height)
{
    int l=0,r=0,lsum=0,rsum=0;
    if(head==NULL)
    {
        *height = 0;
        *sum = 0;
        return;
    }
    fun(head->left,&lsum,&l);
    fun(head->right,&rsum,&r);
    if(l==r)
        *sum = *sum + head->data + lsum;
    else
    {
        if(l>r)
            *sum = *sum + lsum + head->data;
        else
            *sum = *sum + rsum + head->data;
    }
    *height = max(l,r)+1;
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
    head1->left->left->left->right = new Tree(2);
    int sum=0,height=0;
    fun(head1,&sum,&height);
    cout<<sum;
    return 0;
}