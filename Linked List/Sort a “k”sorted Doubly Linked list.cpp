#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
struct Node
{
    Node* next;
    Node* prev;
    int data;
    Node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
void sort(Node* head)
{
    Node* temp=head;
    vector<int> v;
    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    temp=head;
    int i=0;
    while(temp!=NULL)
    {
        temp->data=v[i];
        i++;
        temp=temp->next;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    Node* head=new Node(v[0]);
    Node* temp=head;
    rep(i,1,n)
    {
        temp->next=new Node(v[i]);
        temp=temp->next;
    }
    display(head);
    sort(head);
    newline;
    display(head);
}