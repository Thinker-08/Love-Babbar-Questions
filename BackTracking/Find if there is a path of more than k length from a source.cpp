#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
const int N=1e4+10;
vector<vector<pair<int,int>>> adj(N,vector<pair<int,int>>(N));
vector<int> vis(N,0);
bool driver(int k,int temp,int parent)
{
    if(vis[parent])
        return false;
    if(temp>=k)
        return true;
    vis[parent]=1;
    for(auto child:adj[parent])
    {
        if(driver(k,temp+child.first,child.second))
            return true;
    }
    vis[parent]=0;
    return false;
} 
int32_t main()
{
    fast;
    int n,m,k;
    cin>>n>>m>>k;
    rep(i,0,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    if(driver(k,0,0))
        cout<<"True";
    else
        cout<<"False";
    newline;
    return 0;
}