#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#define ll long long
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.size(),m=s2.size();
  vvi dp(n+1,vi(m+1,-1));
  rep(i,0,n+1)
  {
    rep(j,0,m+1)
    {
      if(i==0||j==0)
      {
        dp[i][j] = 0;
        continue;
      }
      if(s1[i-1]==s2[j-1])
        dp[i][j] = 1+dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
  }
  cout<<dp[n][m];
  return 0;
}