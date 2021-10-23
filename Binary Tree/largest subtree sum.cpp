#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
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
void fun(Tree* head,int* sum)
{
    int lsum=0,rsum=0;
    if(head==NULL)
    {
        *sum=0;
        return;
    }
    fun(head->left,&lsum);
    fun(head->right,&rsum);
    *sum = lsum + rsum + head->data;
    head->data = *sum;
}
int max_sum(Tree* head)
{
    stack<Tree*> s;
    vector<int> v;
    Tree* temp = head;
    while(temp!=NULL || !s.empty())
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        v.push_back(temp->data);
        s.pop();
        temp = temp->right;
    }
    sort(v.begin(),v.end());
    return v[v.size()-1];
}
int main()
{
    bb;bb1;
    Tree* head1 = new Tree(1);
    head1->left = new Tree(-2);
    head1->right = new Tree(3);
    head1->left->left = new Tree(4);
    head1->left->right = new Tree(5);
    head1->right->left = new Tree(-6);
    head1->right->right = new Tree(2);
    int sum=0;
    fun(head1,&sum);
    int a = max_sum(head1);
    cout<<a;
    return 0;
}