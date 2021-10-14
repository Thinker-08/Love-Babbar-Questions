#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)
struct List
{
    int data;
    List* next;
    List(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert(List* head,int val)
{
    List* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new List(val);
}

void display(List* head)
{
    List* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
bool loop(List* head)
{
    List* frog=head;
    List* hare=head;
    while(hare!=NULL)
    {
        hare = hare->next->next;
        frog = frog->next;
        if(frog==hare)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    bb;bb1;
    int n;
    cin>>n;
    List* head = new List(1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    List* temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    bool t = loop(head);
    if(t==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}