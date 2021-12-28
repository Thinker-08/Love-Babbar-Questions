#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
const int N=1e5;
vector<int> adj[N];
int n;
void dfs(vector<int> &vis,int vertex)
{
    vis[vertex]=1;
    for(int child:adj[vertex])
    {
        if(vis[i])
            continue;
        dfs(vis,child);
    }
}
bool isconnected()
{
    vector<int> vi(N,0);
    int count=0;
    for(int i=1;i<n+1;i++)
    {
        if(!vis[i])
        {
            dfs(vis,i);
            count++;
        }
    }
    if(count==1)
        return true;
    else
        return false;
}
bool test=false;
bool dfs_cycle(vector<int> &vis,int vertex,int parent)
{
    vis[vertex]=1;
    for(auto child:adj[vertex])
    {
        if(vis[child]==1 and child==parent)
            continue;
        if(vis[child])
            return true;
        test|=dfs_cycle(vis,child,vertex)
    }
    return test;
}
bool iscyclic()
{
    vector<int> vis(N,0);
    for(int i=1;i<n+1;i++)
    {
        if(vis[i])
            continue;
        if(!dfs_cycle(vis,i,-1))
            return false;
    }
    return true;
}
int main()
{
    fast;

    int m;
    cin>>n>>m;
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(isconnected() and !iscyclic())
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    newline;
    return 0;
}