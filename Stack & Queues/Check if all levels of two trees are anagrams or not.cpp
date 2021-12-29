#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
bool compare(vector<int> a,vector<int> b)
{
    map<int,int> mp;
    if(a.size()==b.size())
    {
        rep(i,0,a.size())
        {
            mp[a[i]]++;
        }
        rep(i,0,b.size())
        {
            if(mp[b[i]]!=0)
            {
                mp[b[i]]--;
                if(mp[b[i]]==0)
                    mp.erase(mp.find(b[i]));
            }
            else
                return false;
        }
        if(mp.size()==0)
            return true;
        else
            return false;
    }
    else
        return false;
}
bool areAnagrams(Node* head1,Node* head2)
{
    if(head1->data!=head2->data)
        return false;
    queue<Node*> q1,q2;
    q1.push(head1);q1.push(NULL);
    q2.push(head2);q2.push(NULL);
    vector<int> a,b;
    while(1)
    {
        Node* temp=q1.front();
        q1.pop();
        if(temp!=NULL and temp->left!=NULL)
        {
            q1.push(temp->left);
            a.push_back(temp->left->data);
        }
        if(temp!=NULL and temp->right!=NULL)
        {
            q1.push(temp->right);
            a.push_back(temp->right->data);
        }
        if(temp==NULL)
        {
            q1.push(NULL);
            while(1)
            {
                Node* temp1=q2.front();
                q2.pop();
                if(temp1!=NULL and temp1->left!=NULL)
                {
                    q2.push(temp1->left);
                    b.push_back(temp1->left->data);
                }
                if(temp1!=NULL and temp1->right!=NULL)
                {
                    q2.push(temp1->right);
                    b.push_back(temp1->right->data);
                }
                if(temp1==NULL)
                {
                    q2.push(NULL);
                    if(compare(a,b))
                        break;
                    else
                        return false;
                }
            }
            a.clear();b.clear();
            if(q1.front()==NULL)
                break;
            else
                continue;
        }
    }
    return true;
}

int main()
{
    fast;
    Node* head1 = new Node(1);
    head1->left=new Node(3);
    head1->right=new Node(2);
    head1->right->left=new Node(5);
    head1->right->right=new Node(4);
    
    Node* head2=new Node(1);
    head2->left=new Node(2);
    head2->right=new Node(3);
    head2->left->left=new Node(4);
    head2->left->right=new Node(5);
    areAnagrams(head1,head2)?cout<<"YES": cout<<"NO";
    newline;
    return 0;
}