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
bool checkUtil(Tree *root,int level, int *leafLevel)
{
    if (root == NULL) 
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (*leafLevel == 0)
        {
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }
    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}
bool check(Tree *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
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
    if(check(head1))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
