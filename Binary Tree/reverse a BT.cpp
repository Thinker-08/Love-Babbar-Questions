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
void display(Tree* head)
{
    queue<Tree*> q;
    q.push(head);
    while(!q.empty())
    {
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        cout<<q.front()->data<<" ";
        q.pop();
    }
}
void reverse(Tree* head)
{
    if(head==NULL)
        return;
    if(head->left!=NULL || head->right!=NULL)
    {
        swap(head->left,head->right);
        reverse(head->left);
        reverse(head->right);
    }
    
}
int main()
{
    bb;bb1;
    Tree* head = new Tree(1);
    head->left = new Tree(2);
    head->right = new Tree(3);
    head->right->left = new Tree(8);
    head->left->left = new Tree(4);
    head->left->right = new Tree(5);
    head->right->right = new Tree(6);
    head->right->right->right = new Tree(7);
    cout<<"ORIGINAL: ";
    display(head);
    cout<<'\n'<<"NEW: ";
    reverse(head);
    display(head);
    return 0;
}