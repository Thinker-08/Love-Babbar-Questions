// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node* temp=head;
        Node* prev=NULL;
        Node* cur=temp;
        while(temp!=NULL)
        {
            temp=temp->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        Node* new_head=prev;
        int flag=1;
        while(flag==1 && prev!=NULL)
        {
            if(prev->data<9)
            {
                prev->data=prev->data+1;
                flag=0;
            }
            else
            {
                prev->data=prev->data+1;
                int x=prev->data/10;
                prev->data=prev->data%10;
                flag=1;
                prev=prev->next;
            }
        }
        temp=new_head;
        Node* x=NULL;
        Node* cur1=temp;
        while(temp!=NULL)
        {
            temp=temp->next;
            cur1->next=x;
            x=cur1;
            cur1=temp;
        }
        if(flag==1)
        {
            Node* t=new Node(1);
            t->next=x;
            return t;
        }
        return x;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends