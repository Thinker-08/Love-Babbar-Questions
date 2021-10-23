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
List* a = NULL;
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

List* reverse(List* head)
{
    List* prev = NULL;
    List* cur = head;
    while(cur!=NULL)
    {
        cur = cur->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}
void recur(List* head,List* prev)
{
    if(head!=NULL)
        recur(head->next,head);
    if(head==NULL)
    {
        a = prev;
        return;
    }    
    head->next = prev;
}
int main()
{
    bb;bb1;
    List* head = new List(1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    cout<<"\n";
    List* newhead = reverse(head);
    display(newhead);
    recur(head,NULL);  
    display(a); 
}