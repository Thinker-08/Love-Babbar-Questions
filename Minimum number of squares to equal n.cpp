#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
const int MOD = 1e7;
int dp[N];
int fun(int n)
{
    if(n==1||n==2||n==3||n==0)
    {
        return n;
    }
    if(dp[n]!=MOD)
    {
        return dp[n];
    }
    for(int i=1;i*i<=n;i++)
    {
        dp[n] = min(dp[n],fun(n-i*i)+1);
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<N;i++)
    {
        dp[i] = MOD;
    }
    cout<<fun(n);
    return 0;
}