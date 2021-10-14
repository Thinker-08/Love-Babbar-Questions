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
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void delnum(List* head,int n)
{
    List* temp = head;
    int count = 0;
    List* prev = NULL;
    while(count!=n)
    {
        count++;
        if(count==n)
            break;
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
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
    List* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    display(head);
    cout<<'\n';
    delnum(head,n);
    display(head);
}