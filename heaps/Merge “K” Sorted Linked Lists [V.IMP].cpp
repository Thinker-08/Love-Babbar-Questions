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
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
struct compare {
    bool operator()(struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};

Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node*,vector<Node*>,compare> pq;
        for(int i=0;i<K;i++)
        {
            Node* temp = arr[i];
            while(temp!=NULL)
            {
                pq.push(temp);
                temp = temp->next;
            }
        }
        Node* x=pq.top(),*temp = pq.top();
        pq.pop();
        while(!pq.empty())
        {
            x->next = pq.top();
            x = x->next;
            pq.pop();
        }
        return temp;
    }
int main()
{
    fast;
    Node* v[4];
    v[0] = new Node(1);
    v[0]->next = new Node(2);
    v[0]->next->next = new Node(3);
    v[1] = new Node(4);
    v[1]->next = new Node(5);
    v[2] = new Node(5);
    v[2]->next = new Node(6);
    v[3] = new Node(7);
    v[3]->next = new Node(8);
    Node *head = mergeKLists(v,4);
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}