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
vector<pair<int,int>> movements{
    {1,0},{-1,0},{0,1},{0,-1}
};
const int N=1e3+10;
int ok=0;
void driver(vector<vector<int>> &matrix,
    pair<int,int> src,pair<int,int> des,
    int temp,vector<vector<int>>& vis)
{
    if(src.first==des.first and 
        src.second==des.second)
    {
        ok=max(ok,temp);
        return;
    }
    if(src.first>=matrix.size() || 
        src.second>=matrix[0].size() ||
     src.first<0 || src.second<0)
        return;
    if(matrix[src.first][src.second]==0 ||
     vis[src.first][src.second]==1)
        return;
    vis[src.first][src.second]=1;
    for(auto move:movements)
    {
        driver(matrix,make_pair(src.first+move.first,
            src.second+move.second),des,temp+1,vis);
    }
    vis[src.first][src.second]=0;
}
int longest_path(vector<vector<int>> &matrix,
    pair<int,int> src,pair<int,int> des)
{
    vector<vector<int>> vis(N,vector<int> (N,0));
    driver(matrix,src,des,0,vis);
    return ok;
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>matrix[i][j];
        }
    }
    pair<int,int> src,des;
    cin>>src.first>>src.second>>des.first>>des.second;
    int ans=longest_path(matrix,src,des);
    cout<<ans;
}