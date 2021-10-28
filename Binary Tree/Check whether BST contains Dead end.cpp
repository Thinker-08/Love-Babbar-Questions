#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool isDeadEnd(Node *head)
{
    vector<Node*> v;
    stack<Node*> s;
    Node* temp = head;
    while(!s.empty() || temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        if(temp->left==NULL && temp->right==NULL)
            v.push_back(temp);
        s.pop();
        temp = temp->right;
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]->data==1)
        {
            int l=false;
            stack<Node*> s;
            temp = head;
            while(!s.empty() || temp!=NULL)
            {
                while(temp!=NULL)
                {
                    s.push(temp);
                    temp = temp->left;
                }
                temp = s.top();
                if(temp->data == v[i]->data+1)
                    l=true;
                s.pop();
                temp = temp->right;
            }
            if(l==true)
                return true;
            else
                continue;
        }
        else
        {
            bool l=false,r=false;
            stack<Node*> s;
            temp = head;
            while(!s.empty() || temp!=NULL)
            {
                while(temp!=NULL)
                {
                    s.push(temp);
                    temp = temp->left;
                }
                temp = s.top();
                if(temp->data == v[i]->data+1)
                    l=true;
                s.pop();
                temp = temp->right;
            }
            temp = head;
            while(!s.empty() || temp!=NULL)
            {
                while(temp!=NULL)
                {
                    s.push(temp);
                    temp = temp->left;
                }
                temp = s.top();
                if(temp->data == v[i]->data-1)
                    r=true;
                s.pop();
                temp = temp->right;
            }
            if(l==true && r==true)
                return true;
            else
                continue;   
        }
    }
    return false;
}