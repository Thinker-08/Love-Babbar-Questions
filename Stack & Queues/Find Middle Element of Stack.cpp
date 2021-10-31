#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int findmiddle(stack<int> s)
{
    vector<int> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v[v.size()/2];
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
    int a=findmiddle(s);
    cout<<a;
    return 0;
}