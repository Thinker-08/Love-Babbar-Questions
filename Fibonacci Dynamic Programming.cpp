#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
int dp[N];
int fun(int n)
{
    if(n==0 ||n==1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = fun(n-1) + fun(n-2);
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
        dp[i] = -1;
    }
    cout<<fun(n);
    return 0;
}