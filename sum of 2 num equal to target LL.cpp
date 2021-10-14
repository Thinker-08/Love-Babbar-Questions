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
    List* prev;
    List(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
void findsum(List* head,int n)
{
    map<int,int> mp;
    List* temp = head;
    int flag = 0;
    while(temp!=NULL)
    {
        if((temp->data + mp[n-temp->data])==n)
        {
            cout<<"The numbers are: "<<temp->data<<" "<<n-temp->data;
            flag = 1;
            break;
        }
        else
        {
            mp[temp->data] = temp->data;
        }
        temp = temp->next;
    }
    if(flag!=1)
    {
        cout<<"NO RESULT FOUND";
    }
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
    display(head);
    findsum(head,n);
}