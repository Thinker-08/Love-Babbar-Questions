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
bool vis[N];
vi adj[N];
/*             1
              / \
             /   \
            2     3
           /|\   /
          / | \ /
         4  5  6
*/
int main()
{
    bb;bb1;
    rep(i,0,N)
        vis[i] = 0;
    int n,m;
    cin>>n>>m;
    int x,y;
    rep(i,0,m)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<endl;
        for(auto it = adj[node].begin();it!=adj[node].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}