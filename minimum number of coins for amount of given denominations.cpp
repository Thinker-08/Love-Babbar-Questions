#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    int amount,n;
    vector<int> coins;
    cin>>amount>>n;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        coins.push_back(temp);
    }
    int dp[n+1][amount+1];
    rep(i,0,n+1)
    {
        rep(j,0,amount+1)
        {
            if(j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j] = 1e5;
            else if(coins[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
        }
    }
    int ans = dp[n][amount]>1e4 ? -1:dp[n][amount];
    cout<<ans;
}