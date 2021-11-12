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
    int data;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
Node* findstartofloop(Node* head)
{
    Node* temp=head;
    Node* ans;
    map<Node*,int>mp;
    while(true)
    {
        if(mp[temp]==0)
            mp[temp]=1;
        else
        {
            ans=temp;
            break;
        }
        temp=temp->next;
    }
    return ans;
}
int main()
{
    fast;
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=head->next;
    Node* loop = findstartofloop(head);
    cout<<loop->data;
    return 0;
}