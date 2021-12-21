#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int main()
{
    fast;
    int n;
    cin>>n;
    queue<int> q1;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        q1.push(temp);
    }
    queue<int> q2;
    rep(i,0,n/2)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int sz=q2.size(),flag=0;
    if(sz<q1.size())
        flag=1;
    rep(i,0,2*sz)
    {
        if(i%2==0 )
        {
            q1.push(q2.front());
            q2.pop();
        }
        else
        {
            int temp=q1.front();
            q1.pop();
            q1.push(temp);
        }
    }
    if(flag==1)
    {
        q1.push(q1.front());
        q1.pop();
    }
    rep(i,0,n)
    {
        cout<<q1.front();
        q1.pop();
        newline;
    }
    return 0;
}