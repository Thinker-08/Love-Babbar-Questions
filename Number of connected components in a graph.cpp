#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define mp map<int,int>
using namespace std;
const int N = 1e5;
vector<bool> vis;
int n,m;
vvi adj;
vi components;
int get_comp(int idx)
{
    if(vis[idx])
        return 0;
    vis[idx] = true;
    int ans = 1;
    for(auto i:adj[idx])
    {
        if(!vis[i])
        {
            ans+=get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    adj = vector<vector<int>> (N);
    vis = vector<bool>(n,false);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<n;i++)  /*initial value of i is taken from input */
    {
        if(!vis[i])
        {
            components.push_back(get_comp(i));
        }

    }
    for(auto it:components)
        cout<<it<<" ";
    return 0;
}