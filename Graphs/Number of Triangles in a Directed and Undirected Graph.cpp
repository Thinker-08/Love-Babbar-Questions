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
vector<int> count_triangles(vector<vector<int>> &direct,vector<vector<int>> &undirect,int n)
{
    vector<int> ans;
    int count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(direct[i][j] and direct[j][k] and direct[k][i])
                    count1++;
                if(undirect[i][j] and undirect[j][k] and undirect[k][i])
                    count2++;
            }
        }
    }
    ans.push_back(count1/3);
    ans.push_back(count2/6);
    return ans;
}
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    const int N=1e4+3;
    vector<vector<int>>direct(N,vector<int> (N,0));
    vector<vector<int>>undirect(N,vector<int> (N,0));
    rep(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        direct[u][v]=1;
        undirect[u][v]=1;
        undirect[v][u]=1;
    }
    vector<int> ans=count_triangles(direct,undirect,n);
    cout<<ans[0]<<" "<<ans[1];
    newline;
    return 0;
}



