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
void nodes_in_range(Tree* head,int* dis,int n1,int n2)
{
    if(head==NULL)
        return ;
    if(head->data<=n2 && head->data>=n1)
        *dis = *dis + 1;
    nodes_in_range(head->left,dis,n1,n2);
    nodes_in_range(head->right,dis,n1,n2);
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
    int count=0;
    nodes_in_range(head1,&count,n1,n2);
    cout<<count;
    return 0;
}