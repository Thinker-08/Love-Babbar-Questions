#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int main()
{
    int n;
    cin>>n;
    vector<int> v(n),ans(n);
    rep(i,0,n)
        cin>>v[i];
    stack<int> s;
    rep(i,0,n)
    {
        if(s.empty())
        {
            s.push(i);
        }
        else
        {
            while(!s.empty() and v[s.top()]>v[i])
            {
                ans[s.top()]=v[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ans[s.top()]=-1;
        s.pop();
    }
    rep(i,0,n)
    {
        cout<<v[i]<<" ";
    }
    newline;
    rep(i,0,n)
    {
        cout<<ans[i]<<" ";
    }
    newline;
}