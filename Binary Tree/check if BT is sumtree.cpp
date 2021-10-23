#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
} ;
bool check_if_sumtree(Tree* head,int* sum)
{
    int l=0,r=0;
    if(head->left==NULL || head->right==NULL)
    {
        *sum = head->data;
        return true;
    }
    if(check_if_sumtree(head->left,&l))
    {
        if(check_if_sumtree(head->right,&r))
        {
            *sum = l+r;
            if(l+r==head->data)
                return true;
        }
    }
    return false;
}
int main()
{
    bb;bb1;
    Tree* head1 = new Tree(10);
    head1->left = new Tree(20);
    head1->right = new Tree(30);
    head1->left->left = new Tree(10);
    head1->left->right = new Tree(10);
    int h = 0;
    bool t = check_if_sumtree(head1,&h);
    if(t)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}