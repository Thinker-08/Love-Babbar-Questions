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
List* mp(List* head1,List* head2)
{
    List* newhead = NULL;
    List* tail = NULL;
    if(head1->data>=head2->data)
    {
        newhead = head2;
        head2 = head2->next;
    }
    else
    {
        newhead = head1;
        head1 = head1->next;
    }
    tail = newhead;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data>head2->data)
        {
            tail->next = head2;
            head2 = head2->next;
        }
        else
        {
            tail->next = head1;
            head1 = head1->next;
        }
        tail = tail->next;
    }
    if(head1!=NULL)
    {
        tail->next = head1;
    }
    if(head2!=NULL)
    {
        tail->next = head2;
    }
    return newhead;
}
List* sorting(List* head)
{
    List* mid = head;
    List* tail = head->next;
    while(mid->next!=NULL && (tail!=NULL && tail->next!=NULL))
    {
        mid = mid->next;
        tail = tail->next->next;
    }
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    List* head2 = mid->next;
    mid->next = NULL;
    List* newhead = mp(sorting(head),sorting(head2));
    return newhead;
}
int main()
{
    bb;bb1;
    List* head = new List(6);
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    display(head);
    List* newhead = sorting(head);
    display(newhead);
}