#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>> v(m);
    rep(i,0,m)
        cin>>v[i].first.first>>v[i].first.second>>v[i].second;
    vector<vector<pair<int,int>>> order(n+1);
    rep(i,0,m)
        order[v[i].second].push_back(v[i].first);
    rep(i,1,n+1)
        sort(order[i].begin(),order[i].end());
    int ans=0;
    for(int i=1;i<n+1;i++)
    {
        int x=0;
        ans++;
        for(int j=1;j<order[i].size();j++)
        {
            if(order[i][x].second<=order[i][j].first)
            {
                x=j;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
        
        