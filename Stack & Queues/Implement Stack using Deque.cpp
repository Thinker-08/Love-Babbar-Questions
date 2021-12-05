#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Stack
{
    public:
        deque<int> dq;
        void dq_push(int val)
        {
            dq.push_front(val);
        }
        void Push(int val)
        {
            dq_push(val);
            display();
        }
        void dq_pop()
        {
            if(!dq.empty())
                dq.pop_front();
            else
                cout<<"UnderFlow";
        }
        void Pop()
        {
            dq_pop();
        }
        void display()
        {
            for(auto it=dq.begin();it!=dq.end();it++)
            {
                cout<<(*it)<<" ";
            }
            newline;
        }
};
int main()
{
    fast;
    cout<<" Choice 1: PUSH"<<'\n'<<"Choice 2: POP";
    newline;
    int n;
    cin>>n;
    while(n--)
    {
        Stack obj;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int temp;
            cin>>temp;
            obj.Push(temp);
        }
        if(choice==2)
        {
            obj.Pop();
        }
    }
    return 0;
}