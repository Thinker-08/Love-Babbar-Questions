#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
struct DLLNode{
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
int countTriplets(DLLNode* head, int x)
{
    int count=0;
    while(head!=NULL)
    {
        DLLNode* temp=head->next;
        while(temp!=NULL)
        {
            DLLNode* temp1=temp->next;
            while(temp1!=NULL)
            {
                if(head->data+temp->data+temp1->data==x)
                    count++;
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        head=head->next;
    }
    return count;
}  
int main()
{
    fast;
    DLLNode* head=new DLLNode(1);
    DLLNode* temp=head;
    head->next=new DLLNode(2);
    head->next->prev=head;
    head=head->next;
    head->next=new DLLNode(3);
    head->next->prev=head;
    head=head->next;
    int x;
    cin>>x;
    int ans=countTriplets(temp,x);
    cout<<ans;
    return 0;
}