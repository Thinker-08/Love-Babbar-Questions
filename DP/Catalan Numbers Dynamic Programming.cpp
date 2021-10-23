#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL);
int main()
{
    bb;bb1;
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    for(int i=0;i<=n;i++)
    {
        if(i==0)
            dp[i] = 1;
        else if(i==1)
            dp[i] = 1;
        else
        {
            for(int j=0;j<i;j++)
            {
                dp[i] = dp[i] + dp[j]*dp[i-1-j];
            }
        }
    }
    rep(i,0,n+1)
    {
        cout<<dp[i]<<" ";
    }
    return 0;
}