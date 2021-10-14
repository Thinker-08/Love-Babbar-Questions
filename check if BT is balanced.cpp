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
bool check_if_bal(Tree* head,int* height)
{
    int l=0,r=0;
    if(head==NULL)
    {
        *height = 0;
        return true;
    }
    if(check_if_bal(head->left,&l))
    {
        if(check_if_bal(head->right,&r))
        {
            *height = max(l,r)+1;
            if(abs(l-r)<=1)
                return true;
        }
    }
    return false;
}
int main()
{
    bb;bb1;
    Tree* head1 = new Tree(1);
    head1->left = new Tree(2);
    head1->right = new Tree(3);
    head1->left->left = new Tree(4);
    head1->left->right = new Tree(5);
    head1->left->left->left = new Tree(6);
    int h = 0;
    bool t = check_if_bal(head1,&h);
    if(t)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}