#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
const int N=1e5;
vector<vector<int>> adj(N);
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> indeg(N,0);
    rep(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    int level[n];
    queue<int> q;
    rep(i,1,n+1)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            level[i]=1;
        }
    }
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto child: adj[temp])
        {
            indeg[child]--;
            if(indeg[child]==0)
            {
                q.push(child);
                level[child]=level[temp]+1;
            }
        }
    }
    rep(i,1,n+1)
        cout<<level[i]<<" ";
    return 0;
}