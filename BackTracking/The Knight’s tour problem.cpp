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
const int N=1e3+10;
vector<pair<int,int>> movements{
    {2,1},{2,-1},{-2,1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
};
bool path(vector<vector<int>> &vis,int i,int j,int n,int t)
{
    if(i<0 || j<0 || i>=n || j>=n)
        return false;
    if(vis[i][j]!=-1)
        return false;
    if(t==(n*n-1))
    {
        vis[i][j]=t;
        return true;
    }
    vis[i][j]=t;
    for(auto move:movements)
    {
        if(path(vis,i+move.first,j+move.second,n,t+1))
            return true;
    }
    vis[i][j]=-1;
    return false;
}
void print_path(vector<vector<int>> &vis,int n)
{
    rep(i,0,n)
    {
        rep(j,0,n)
            cout<<vis[i][j]<<" ";
        newline;
    }
}
int32_t main()
{
    vector<vector<int>> vis(N,vector<int> (N,-1));
    int n;
    cin>>n;
    if(path(vis,0,0,n,0))
        print_path(vis,n);
    else
        cout<<-1;
    newline;
}