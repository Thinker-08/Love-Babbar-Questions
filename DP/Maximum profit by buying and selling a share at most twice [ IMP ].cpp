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
int maxProfit(vector<int>& prices)
{
    vector<vector<int>> dp(3,vector<int> (prices.size()+1));
    for(int i=0;i<3;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<prices.size()+1;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<3;i++)
    {
        int prev=INT_MIN;
        for(int j=1;j<prices.size();j++)
        {
            prev=max(prev,dp[i-1][j-1]-prices[j-1]);
            dp[i][j]=max(dp[i][j-1],prev+prices[j]);
        }
    }
    return dp[2][prices.size()-1];
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> prices(n);
    rep(i,0,n)
        cin>>prices[i];
    int ans=maxProfit(prices);
    cout<<ans;
    return 0;
}