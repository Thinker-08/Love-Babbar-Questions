#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#define MOD 1e9+7
#define const int N=1e5;
void dfs(int i,int j,vector<vector<int>> &image,int initialc,int finalc)
{
    if(i<0 || j<0)
        return;
    if(i>=image.size() || j>=image[0].size())
        return;
    if(image[i][j]!=initialc)
        return;
    image[i][j]=finalc;
    dfs(i+1,j,image,initialc,finalc);
    dfs(i-1,j,image,initialc,finalc);
    dfs(i,j+1,image,initialc,finalc);
    dfs(i,j-1,image,initialc,finalc);
        
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if(image[sr][sc]!=newColor)
        dfs(sr,sc,image,image[sr][sc],newColor);
    return image;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(N,vector<int>(N));
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int sr,sc,newColor;
    cin>>sr>>sc>>newColor;
    vector<vector<int>> ans=floodFill(adj,sr,sc,newColor);
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cout<<ans[i][j]<<" ";
        }
        newline;
    }
    return 0;
}