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
int n,m;
const int INF = 1e9;
vvi g[N];
vector<bool> vis(N);
int cost = 0;
vi dist(N),parent(N);
//INPUT------------------------>
                                                        /*4 5
                                                        0 1 10
                                                        0 2 5
                                                        1 2 15
                                                        2 3 40
                                                        1 3 2*/
void primsMST(int source)
{
    rep(i,0,n)
    {
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0,source});
    while(!s.empty())
    {
        auto x = *(s.begin());
        vis[x[1]] = true;
        s.erase(x);
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost = cost + w;
        for(auto it: g[x[1]])
        {
            if(vis[it[0]])
            {
                continue;
            }
            if(dist[it[0]]>it[1])
            {
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    rep(i,0,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    primsMST(0);
    cout<<cost;
    return 0;
}