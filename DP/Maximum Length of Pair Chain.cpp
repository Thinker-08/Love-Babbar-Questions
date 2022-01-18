#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
bool cmp(vector<int> &a,vector<int>& b)
{
    return a[1]<b[1];
}
int findLongestChain(vector<vector<int>>& pairs)
{
    const int N=1e4;
    vector<int>dp(N,1);
    sort(pairs.begin(),pairs.end(),cmp);
    int maxi=1;
    for(int i=0;i<pairs.size();i++)
    {
        int l=pairs[i][0],r=pairs[i][1];
        for(int j=0;j<pairs.size();j++)
        {
            if(i>=j)
                continue;
            else
            {
                if(pairs[j][0]>r)
                {
                    dp[j]=dp[j-1]+1;
                    l=pairs[j][0];
                    r=pairs[j][1];
                }
                else
                {
                    dp[j]=dp[j-1];
                }
            }
            maxi=max(maxi,dp[j]);
        }
    }
    return maxi;        
}
int32_t main()
{
    fast;
    int n;
    cin>>n;
    vector<vector<int>> pairs(n);
    rep(i,0,n)
    {
        int a,b;
        cin>>a>>b;
        pairs[i]={a,b};
    }
    cout<<findLongestChain(pairs);
    return 0;
}