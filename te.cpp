#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void insert(Node* head,int val)
{
    Node* temp = head;
    if(val>head->data)
    {
        if(head->right!=NULL)
        {
            insert(head->right,val);
        }
        else
        {
            head->right = new Node(val);
        }
    }
    else
    {
        if(head->left!=NULL)
        {
            insert(head->left,val);
        }
        else
        {
            head->left = new Node(val);
        }
    }
}
void display(Node* head)
{
    if(head->left!=NULL)
    {
        display(head->left);
    }
    cout<<head->data<<" ";
    if(head->right!=NULL)
    {
        display(head->right);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* head = new Node(5);
    insert(head,6);
    insert(head,4);
    insert(head,2);
    insert(head,7);
    display(head);
    return 0;
}