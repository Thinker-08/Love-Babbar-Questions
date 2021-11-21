#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Node
{
    public:
        char data;
        Node* next;
        Node* pre;
    Node(int data)
    {
        this->data=data;
        pre=NULL;
        next=NULL;
    }
};
 
void insertAtHead(Node* &head, int data)
{
    Node* n = new Node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    n->next=head;
    head->pre=n;
    head=n;
    return;
}
void insertAtTail(Node* &head, int data)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* n=new Node(data);
    temp->next=n;
    n->pre=temp;
    return;
}
void display(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data << "-->";
        head=head->next;
    }
    cout << "NULL\n";
}
Node* rotate(Node* head,int n)
{
    Node* temp=head;
    int count=1;
    while(count!=n)
    {
        temp=temp->next;
        count++;
    }
    temp=temp->next;
    temp->pre=NULL; 
    Node* x=temp;
    Node* new_head=temp;
    temp=temp->next;
    Node* prev=temp;
    while(temp!=NULL)
    {
        new_head->next=new Node(temp->data);
        temp=temp->next;
        new_head->pre=prev;
        prev=new_head;
        new_head=new_head->next;
    }
    if(temp==NULL)
        return reverse(head);
    temp=head;
    prev=new_head;
    count=1;
    while(count!=n)
    {
        new_head->next=new Node(temp->data);
        temp=temp->next;
        new_head->pre=prev;
        prev=new_head;
        new_head=new_head->next;
        count++;
    }
    new_head->next=temp;
    new_head=new_head->next;
    new_head->next=NULL;
    return x;
}
int main()
{
    Node* head=NULL;
    insertAtTail(head,'a');
    insertAtTail(head,'b');
    insertAtTail(head,'c');
    insertAtTail(head,'d');
    insertAtTail(head,'e');
    int n;
    cin>>n;
    cout<<"Before: ";display(head);
    Node* new_head=rotate(head,n);
    newline;
    cout<<"After: ";display(new_head);
}