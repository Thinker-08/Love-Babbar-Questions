// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* reversell(Node* head)
    {
        if(head->next==NULL)
            return head;
        Node* prev = NULL;
        Node* cur = head;
        while(cur!=NULL)
        {
            cur = cur->next;
            head->next = prev;
            prev = head;
            head = cur;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        int flag=0;
        while(head->next!=NULL)
        {

            int first = head->data;
            head=reversell(head);
            if(first==head->data)
            {
                head=head->next;
                head=reversell(head);
                if(head->next==NULL)
                    break;
                head=head->next;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            return false;
        else
            return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends