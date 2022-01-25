// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int find(int in[],int start,int end,int cur,int n)
    {
        for(int i=start;i<=end;i++)
            if(in[i]==cur)
                return i;
        return -1;
    }
    Node* build(int in[],int pre[],int n,int start,int end)
    {
        static int idx=0;
        if(start>end)
            return NULL;
        Node* head=new Node(pre[idx]);
        idx++;
        if(start==end)
            return head;
        int x=find(in,start,end,head->data,n);
        head->left=build(in,pre,n,start,x-1);
        head->right=build(in,pre,n,x+1,end);
        return head;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        return build(in,pre,n,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends