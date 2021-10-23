#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
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
};

void insert(Tree* head,int val)
{
    if(head->left==NULL && head->data>val)
        {
            head->left = new Tree(val);
            return;
        }
    if(head->right==NULL && head->data<val)
        {
            head->right = new Tree(val);
            return;
        }
    if(head->data>val)
        insert(head->left,val);
    else
        insert(head->right,val);
}
void inserting(Tree* head,vi v)
{
    for(auto i = v.begin();i!=v.end();i++)
        insert(head,*i);
}
void level_display(Tree* head)
{
    vector<int> v;
    v.push_back(head->data);
    queue<Tree*> q;
    q.push(head);
    while(!q.empty())
    {
        if(q.front()->left!=NULL)
        {
            v.push_back(q.front()->left->data);
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL)
        {
            v.push_back(q.front()->right->data);
            q.push(q.front()->right);
        }
        q.pop();
    }
    rep(i,0,v.size())
        cout<<v[i]<<" ";
}
void inorder_display(Tree* head)
{
    if(head==NULL)
        return;
    inorder_display(head->left);
    cout<<head->data<<" ";
    inorder_display(head->right);
}

void fun(Tree* head,int k)
{
    Tree* temp = head;
    vector<Tree*> v;
    stack<Tree*> s;
    while(!s.empty() || temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        v.push_back(temp);
        temp = temp->right;
    }
    cout<<v[k-1]->data;
}
int main()
{
    bb;bb1;
    Tree* head = new Tree(5);
    vi v = {3,1,2,7,6,8,10};
    inserting(head,v);
    int k;
    cin>>k;
    fun(head,k);
    return 0;
} 