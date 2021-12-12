#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int main()
{
    fast;
    string s;
    cin>>s;
    vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
    for(int k=0;k<s.length();k++)
    {
        for(int i=0,j=k;j<s.length();i++,j++)
        {
            if(i==j)
                dp[i][j]=1;
            else
            {
                if(abs(j-i)==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=2;
                    else
                    {
                        dp[i][j]=1;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1]+2;
                    else
                    {
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }
    }
    cout<<dp[0][s.length()-1];
    return 0;
}