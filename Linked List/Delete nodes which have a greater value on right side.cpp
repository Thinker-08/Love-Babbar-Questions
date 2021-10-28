// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head->next==NULL)
            return head;
        else
        {
            Node* temp = head,* temp1;
            Node* cur = head;
            while(head->next!=NULL)
            {
                if(head->next->data>head->data)
                {
        
                    if(head->next->next!=NULL)
                    {
                        if(head->next->next->data<head->next->data)
                        {
                            temp = head->next;
                            cur = head->next;
                            break;
                        }
                    }
                    else
                    {
                        temp = head->next;
                        cur = head->next;
                        break;
                    }
                }
                head=head->next;
            }
            temp1 = temp;
            while(cur->next!=NULL)
            {
                if(cur->next->data>cur->data)
                {
                    temp->next = cur->next;
                    temp = temp->next;
                }
                cur = cur->next;
            }
            return temp1;   
        }
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends