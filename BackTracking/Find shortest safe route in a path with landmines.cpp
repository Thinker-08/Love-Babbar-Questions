#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
bool isvalid(vector<vector<int>>& field,int i,int j)
{
    if(i<0 || j<0 || i>=field.size() || j>=field[0].size())
        return false;
    return true;
}
const int N=1e3+10;
vector<vector<int>> vis(N,vector<int>(N,0));
int ans=INT_MAX;
vector<pair<int,int>> movements{
    {1,0},{-1,0},{0,1},{0,-1}
};
void shortest(vector<vector<int>> &field,int i,int j,int dis)
{
    if(!isvalid(field,i,j))
        return;
    if(vis[i][j]==1 || field[i][j]==0)
        return;
    if(j==field[0].size()-1 and ans>dis)
    {
        ans=dis;
        return;
    }
    vis[i][j]=1;
    for(auto move:movements)
    {
        shortest(field,i+move.first,j+move.second,dis+1);
    }
    vis[i][j]=0;
}
void reset()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            vis[i][j]=0;
    }
    ans=INT_MAX;    
}
int shortestPath(vector<vector<int>> &field)
{
    reset();
    vector<pair<int,int>> zeros;
    for(int i=0;i<field.size();i++)
    {
        for(int j=0;j<field[i].size();j++)
        {
            if(field[i][j]==0)
            {
                if(isvalid(field,i+1,j))
                    zeros.push_back({i+1,j});
                if(isvalid(field,i-1,j))
                    zeros.push_back({i-1,j});
                if(isvalid(field,i,j+1))
                    zeros.push_back({i,j+1});
                if(isvalid(field,i,j-1))
                    zeros.push_back({i,j-1});
            }
        }
    }
    for(int i=0;i<zeros.size();i++)
    {
        field[zeros[i].first][zeros[i].second]=0;
    }
    rep(i,0,field.size())
    {
        rep(j,0,field[i].size())
            cout<<field[i][j]<<" ";
        newline;
    }
    for(int i=0;i<field.size();i++)
    {
        shortest(field,i,0,0);
    }
    return ans==INT_MAX?-1:ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(m));
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>v[i][j];
            }
        }
        int ok = shortestPath(v);
        cout<<ok;
        newline;
    }
    return 0;
}