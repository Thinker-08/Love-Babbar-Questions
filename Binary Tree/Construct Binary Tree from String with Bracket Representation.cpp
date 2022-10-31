//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    bool check(int r,int l,string &s)
    {
        int count=0;
        for(int i=l;i<=r;i++)
        {
            if(s[i]=='(' or s[i]==')')
            count++;
        }
        if(count==2)
            return true;
        return false;
    }
    Node* find_tree(string &s,int l,int r)
    {
        if(l>=s.length()+1)
            return NULL;
        if(check(r,l,s))
        {
            int num=0;
            int x=l+1;
            while(x<s.length() and s[x]!='(' and s[x]!=')')
            {
                num=num*10+(s[x]-'0');
                x++;   
            }
            Node* temp = new Node(num);
            return temp;
        }
        stack<char> st;
        int x=l+1,num=0;
        while(x<s.length() and s[x]!='(' and s[x]!=')')
        {
            num=num*10+(s[x]-'0');
            x++;
        }
        Node* temp = new Node(num);
        int idx;
        for(int i=x;i<=r;i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                st.pop();
                if(st.empty())
                {
                    temp->left = find_tree(s,x,i);
                    idx=i;
                    break;
                }
            }
        }
        for(int i=idx+1;i<=r;i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                st.pop();
                if(st.empty())
                {
                    temp->right = find_tree(s,idx+1,i);
                    break;
                }
            }
        }
        return temp;
    }
    Node *treeFromString(string str)
    {
        string temp="(";
        for(int i=0;i<str.length();i++)
            temp+=str[i];
        temp+=')';
        return find_tree(temp,0,temp.length()-1);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends