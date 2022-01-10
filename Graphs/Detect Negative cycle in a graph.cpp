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
vector<vector<int>> adj(N,vector<int>(N));
vector<int> dis(N,INT_MAX); 
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    rep(i,0,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj.push_back({x,y,w});
    }
    dis[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto it:adj)
        {
            if(dis[it[0]]+it[2]<dis[it[1]])
                dis[it[1]]=dis[it[0]]+it[2];
        }
    }
    int flag=0;
    for(auto it:adj)
    {
        if(dis[it[0]]+it[2]<dis[it[1]])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}