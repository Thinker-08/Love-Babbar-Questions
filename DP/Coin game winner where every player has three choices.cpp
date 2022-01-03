#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
int main()
{
    fast;
    int n,a,b;
    cin>>n>>a>>b;
    bool dp[n+1];
    dp[0]=false;
    dp[1]=true;
    for(int i=2;i<=n;i++)
    {
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - a >= 0 and !dp[i - a])
            dp[i] = true;
        else if (i - b >= 0 and !dp[i - b])
            dp[i] = true;
        else
            dp[i] = false;
    }
    if(dp[n])
        cout<<"A";
    else
        cout<<"B";
    return 0;
}