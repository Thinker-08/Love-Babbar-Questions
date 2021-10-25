#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
struct Tree
{
    int data;
    Tree* left;
    Tree* right;
    Tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
vector<int> leftView(Tree* head)
{
    vector<int> v;
    if(root==NULL)
        return v;
    Tree* temp = head;
    queue<Tree*> q;
    q.push(temp);
    while(!q.empty())
    {
        int n=q.size();
        rep(i,0,n)
        {
            temp = q.front();
            q.pop();
            if(i==n-1)
                v.push_back(temp->data);
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
    return v;
}
int main()
{
    Tree* head = new Tree(1);
    head->left= new Tree(2);
    head->right = new Tree(3);
    head->left->left = new Tree(4);
    head->left->right = new Tree(5);
    head->left->right->left = new Tree(6);
    head->right->right = new Tree(7);
    head->right->right->right = new Tree(8);
    head->right->right->right->left = new Tree(9);
    vector<int> v = leftView(head);
    rep(i,0,v.size())
    {
        cout<<v[i]<<" ";
    }
    return 0;    
}