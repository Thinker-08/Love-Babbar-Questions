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
int height;
bool calc(Node* head,int from,int &k)
{
    if(head==NULL)
        return false;
    if(head->data==from)
        return true;
    else
    {
        if(calc(head->left,from,k) || calc(head->right,from,k))
        {
            k--;
            if(k==0)
            {
                height=head->data;
                return true;
            }
            else
                return true;
        }
        else
            return false;
    }
}
int32_t main()
{
    fast;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int k,node;
    cin>>k>>node;
    if(calc(root,node,k))
        cout<<height;
    else
        cout<<-1;
    newline;
    return 0;
}