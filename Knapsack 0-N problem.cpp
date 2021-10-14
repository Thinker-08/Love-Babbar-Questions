#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
const int N=1e5;
int main()
{
    int max_weight,n;
    cin>>n>>max_weight;
    int val[n],wt[n];
    vector<int> dp(max_weight+1,0);
    rep(i,0,n)
    {
        cin>>val[i];
    }
    rep(i,0,n)
    {
        cin>>wt[i];
    }
    int ans=0;
    for(int i=0;i<=max_weight;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-wt[j]>=0)
            {
                dp[i] = max(dp[i],val[j]+dp[i-wt[j]]);
            }
        }
    }
    cout<<dp[max_weight];
    return 0;
}