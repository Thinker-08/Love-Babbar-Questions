#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
void insert(Node* head,int key)
{
    if(head->data>key)
    {
        if(head->left==NULL)
        {
            head->left=new Node(key);
        }
        else
        {
            insert(head->left,key);
        }
    }
    else
    {
        if(head->right==NULL)
        {
            head->right=new Node(key);
        }
        else
        {
            insert(head->right,key);
        }
    }
}
Node* inorder_succ(Node* head,int key)
{
    Node* sus=NULL;
    while(head!=NULL)
    {
        if(head->data>key)
        {
            sus=head;
            head=head->left;
        }
        else
            head=head->right;
    }
    return sus;
} 
int32_t main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    if(n==1)
        cout<<v[0];
    else
    {
        Node* head=new Node(v[n-1]);
        v[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            insert(head,v[i]);
            Node* ans=inorder_succ(head,v[i]);
            if(ans==NULL)
                v[i]=-1;
            else
                v[i]=ans->data;
        }
        rep(i,0,n)
            cout<<v[i]<<" ";
        newline;
    }
}