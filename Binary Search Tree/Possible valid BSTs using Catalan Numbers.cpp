#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL);
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
vector<Node*> constructTrees(int start,int end)
{
    vector<Node*> trees;
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++)
    {
        vector<Node*> leftsubtrees = constructTrees(start,i-1);
        vector<Node*> rightsubtrees = constructTrees(i+1,end);
        for(int j=0;j<leftsubtrees.size();j++)
        {
            Node* left = leftsubtrees[j];
            for(int k=0;k<rightsubtrees.size();k++)
            {
                Node* right = rightsubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    bb;bb1;
    vector<Node*> v = constructTrees(1,3);
    rep(i,0,5)
    {   
        preorder(v[i]);
        cout<<'\n';
    }
    return 0;
}