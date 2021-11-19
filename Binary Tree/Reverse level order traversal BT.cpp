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
void fun(Tree* head)
{
    queue<Tree*> q;
    vector<int> v;
    q.push(head);
    while(!q.empty())
    {
        if(q.front()->right!=NULL)
        {
            q.push(q.front()->right);
        }
        if(q.front()->left!=NULL)
        {
            q.push(q.front()->left);
        }
        v.push_back(q.front()->data);
        q.pop();
    }
    reverse(v.begin(),v.end());
    rep(i,0,v.size())
    {
        cout<<v[i]<<" ";
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
    fun(head);
    return 0;
}