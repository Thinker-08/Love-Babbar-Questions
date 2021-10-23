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
bool find(Tree* head,int val)
{
    if(head==NULL)
        return false;
    if(head->data==val)
        return true;
    if(head->data>val)
        if(find(head->left,val))
            return true;
    if(head->data<val)
        if(find(head->right,val))
            return true;
    return false;
}
Tree* deleteT(Tree* head,int val)
{
    if(head==NULL)
        return head;
    if(head->data>val)
    {
        head->left = deleteT(head->left,val);
        return head;
    }
    if(head->data<val)
    {
        head->right = deleteT(head->right,val);
        return head;
    }    
    else
    {
        if(head->left==NULL)
        {
            Tree* temp = head->right;
            delete head;
            return(temp);
        }
        else if(head->right==NULL)
        {
            Tree* temp = head->left;
            delete head;
            return(temp);
        }
        else
        {
            Tree* temp = head;
        Tree* cur = head->right;
        while (cur->left != NULL)
        {
            temp = cur;
            cur = cur->left;
        }
        if (temp != head)
            temp->left = cur->right;
        else
            temp->right = cur->right;
        head->data = cur->data;
        delete cur;
        return head;
        }
    }
}
int main()
{
    bb;bb1;
    Tree* head = new Tree(5);
    vi v = {1,2,6,7,3,8,10,4};
    inserting(head,v);
    int n;
    cin>>n;
    if(!find(head,n))
    {
        cout<<"NOT FOUND AND HENCE INSERTED";
        insert(head,n);
        cout<<endl;
        level_display(head);
    }
    else
    {
        cout<<"FOUND HENCE DELETED";
        cout<<endl;
        Tree* head1 = deleteT(head,n);
        level_display(head1);
    }
    return 0;
}