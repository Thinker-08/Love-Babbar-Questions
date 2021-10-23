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
            return; //IMPORTANT
        }
    if(head->right==NULL && head->data<val)
        {
            head->right = new Tree(val);
            return; //IMPORTANT
        }
    if(head->data>val)
        insert(head->left,val);
    else
        insert(head->right,val);
}

void inorder_display(Tree* head)
{
    if(head==NULL)
        return;
    inorder_display(head->left);
    cout<<head->data<<" ";
    inorder_display(head->right);
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

int main()
{
    bb;bb1;
    Tree* head = new Tree(5);
    insert(head,1);
    insert(head,2);
    insert(head,6);
    insert(head,7);
    insert(head,3);
    insert(head,8);
    insert(head,10);
    insert(head,4);
    int n;
    cin>>n;
    cout<<endl;
    if(!find(head,n))
    {
        cout<<"NOT FOUND AND HENCE INSERTED";
        insert(head,n);
    }
    else
        cout<<"FOUND";
    return 0;
}