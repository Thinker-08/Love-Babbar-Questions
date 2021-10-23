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
List* fun(vector<List*> &v)
{
    List* newhead = v[0];
    List* tail = NULL;
    int j = 0;
    rep(i,0,v.size())
    {
        if(newhead->data>v[i]->data)
        {
            newhead = v[i];
            j = i;
        }
        else
            continue;
    }
    v[j] = v[j]->next;
    tail = newhead;
    while(any_of(v.begin(),v.end(),[](List* x){return x!=NULL;}))
    {
        List* temp;
        rep(i,0,v.size())
        {
            if(v[i]!=NULL)
            {
                temp = v[i];
                j = i;
            }    
        }
        rep(i,0,v.size())
        {
            if(v[i]==NULL)
            {
                continue;
            }
            else
            {
                if(temp->data>v[i]->data)
                {
                    temp = v[i];
                    j = i;
                }
            }
        }
        tail->next = temp; 
        tail = tail->next;
        v[j] = v[j]->next;
    }
    tail->next = NULL;
    return newhead;
}
int main()
{
    bb;bb1;
    int n;
    cin>>n;
    vector<List*> v;
    rep(i,0,n)
    {
        int size;
        cin>>size;
        int dat;
        cin>>dat;
        List* head = new List(dat);
        rep(j,0,size-1)
        {
            int val;
            cin>>val;
            insert(head,val);
        }
        v.push_back(head);
    }
    rep(i,0,n)
    {
        display(v[i]);
        cout<<"\n";
    }
    List* newhead = fun(v);
    display(newhead);
}