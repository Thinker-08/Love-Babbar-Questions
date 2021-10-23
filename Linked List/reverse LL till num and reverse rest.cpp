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
List* common(List* head,List* end)
{
    List* temp=head;
    List* prev = NULL;
    while(temp!=end)
    {
        temp = temp->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
List* reverse(List* head,int n)
{
    int count = 0;
    List* temp = head;
    while(temp!=NULL)
    {
        count++;
        if(count==n)
        {
            break;
        }    
        temp = temp->next;
    }
    List* after=temp->next;
    if(after==NULL)
    {
        head = common(head,after);
        return head;
    }
    else
    {
        List* cur = common(head,after);
        List* t = cur;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }
        head = common(after,NULL);
        cur->next = head;
        return t;
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
    display(head);
    cout<<"\n";
    head = reverse(head,n);
    display(head);
}