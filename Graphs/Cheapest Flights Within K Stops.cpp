#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
const int N=1e5;
vector<vector<int>> adj(N);
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
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        const int N=1e5;
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> prices(N,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        prices[src]=0;
        while(!q.empty())
        {
            if(k==-1)
                break;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                pair<int,int> cur=q.front();
                q.pop();
                for(auto vert : adj[cur.first])
                {
                    if(prices[vert.first]==-1 || cur.second+vert.second<prices[vert.first])
                    {
                        prices[vert.first]=cur.second+vert.second;
                        q.push({vert.first,prices[vert.first]});
                    }
                }
            }
            k--;
        }
        return prices[dst];
    }
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> flights;
    rep(i,0,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        flights.push_back({u,v,w});
    }
    int src,des,k;
    cin>>src>>des>>k;
    int ans=findCheapestPrice(m,flights,src,des,k);
    cout<<<ans;
    return 0;
}



