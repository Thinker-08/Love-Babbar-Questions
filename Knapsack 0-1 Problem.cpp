#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N = 1e4;
const int MOD = 1e7;
int val[N], wt[N];
int dp[N][N];
int fun(int n, int max_value)
{
    if(max_value<=0)
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }
    if(dp[n][max_value]!=-1)
    {
        return dp[n][max_value];
    }
    if(wt[n-1]>max_value)
    {
        dp[n][max_value]  = fun(n-1,max_value);
    }
    else
    {
        int q1 = fun(n-1,max_value-wt[n-1]) + val[n-1];
        int q2 = fun(n-1,max_value);
        dp[n][max_value] = max(q1,q2);
    }
    return dp[n][max_value];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max_value,n;
    cin>>n>>max_value;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        val[i] = temp;
    }
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        wt[i] = temp;
    }
    rep(i,0,N)
    {
        rep(j,0,N)
        {
            dp[i][j] = -1;
        }
    }
    cout<<fun(n,max_value);
    return 0;
}