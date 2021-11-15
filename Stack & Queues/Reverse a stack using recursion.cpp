#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
stack<int> new_stack;
void reverse(stack<int> s)
{
    if(s.size()==0)
    {
        return;
    }
    new_stack.push(s.top());
    s.pop();
    reverse(s);
}
void display(stack<int> s)
{
    stack<int> temp;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
int main()
{
    fast;
    int n;
    cin>>n;
    stack<int> s;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }
    cout<<"Before: ";
    display(s);
    reverse(s);
    newline;
    cout<<"After: ";
    display(new_stack);
    return 0;
}