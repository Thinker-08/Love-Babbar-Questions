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
void mirror(Tree* head)
{
    if(head==NULL)
        return;
    if(head->left!=NULL || head->right!=NULL)
    {
        swap(head->left,head->right);
        mirror(head->left);
        mirror(head->right);
    }
    
}
bool check(Tree* head1,Tree* head2)
{
    if(head1==NULL && head2==NULL)
    {
        return true;
    }
    if(head1==NULL && head2!=NULL)
        return false;
    if(head1!=NULL && head2==NULL)
        return false;
    if(head1->data==head2->data)
    {
        if(check(head1->left,head2->left))
        {
            if(check(head1->right,head2->right))
                return true;
        }
    }
    return false;
}
void display(Tree* head)
{
    if(head==NULL)
        return;
    else
    {
        display(head->left);
        cout<<head->data<<" ";
        display(head->right);
    }
}
int main()
{
    bb;bb1;
    Tree* head1 = new Tree(1);
    head1->left = new Tree(2);
    head1->right = new Tree(3);
    head1->left->left = new Tree(4);
    head1->left->right = new Tree(5);
    mirror(head1);
    Tree* head2 = new Tree(1);
    head2->left = new Tree(2);
    head2->right = new Tree(3);
    head2->left->left = new Tree(4);
    head2->left->right = new Tree(5);
    bool t = check(head1,head2);
    if(t)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;display(head1);cout<<endl;
    display(head2);
    return 0;
}