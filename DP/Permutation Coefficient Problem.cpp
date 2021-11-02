#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
long long nCr(int n,int r)
{
    long long dp[r+1][n+1];
    for(int i=0;i<r+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
                dp[i][j]=1;
            else
            {
                if(i>j)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=(dp[i][j-1]+i*dp[i-1][j-1])%1000000007;
                }
            }
        }
    }
    return dp[r][n];
}
int main()
{
    fast;
    int n,r;
    cin>>n>>r;
    ll value=nCr(n,r);
    cout<<value;
    return 0;  
}