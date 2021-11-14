#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> ans;
    rep(i,0,n)
        cin>>v[i];
    int dp[n][n];
    rep(i,0,n)
    {
        dp[i][i]=v[i];
        ans.push_back(dp[i][i]);
    }
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            if(i>j)
                dp[i][j]=0;
            else
            {
                if(i==j)
                    continue;
                else
                {
                    dp[i][j]=dp[i][j-1]+v[j];
                    ans.push_back(dp[i][j]);
                }
            }
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout<<ans[k-1];
    return 0;
}