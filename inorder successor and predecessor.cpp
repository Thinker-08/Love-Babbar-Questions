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

Tree* find(Tree* head,int n)
{
    if(head==NULL)
        return NULL;
    if(head->data==n)
        return head;
    if(head->data>n)
        return find(head->left,n);
    if(head->data<n)
        return find(head->right,n);
}

Tree* inorder_succ(Tree* head,int n)
{
    Tree* temp = find(head,n);
    if(temp==NULL || temp->right==NULL)
        return NULL;
    temp = temp->right;
    while(temp->left!=NULL)
        temp = temp->left;
    return temp;
}
Tree* inorder_pred(Tree* head,int n)
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
    rep(i,0,v.size()-1)
    {
        if(v[i+1]->data==n)
            return v[i];
    }
}
int main()
{
    bb;bb1;
    Tree* head = new Tree(5);
    vi v = {1,2,6,7,3,8,10,4};
    inserting(head,v);
    int n1,n2;
    cin>>n1>>n2;
    Tree* a = inorder_succ(head,n1);
    Tree* b = inorder_pred(head,n2);
    cout<<"INORDER SUCCESSOR OF "<<n1<<" IS: "<<a->data<<endl;
    cout<<"INORDER PREDECESSOR OF "<<n2<<" IS: "<<b->data<<endl;
    return 0;
}