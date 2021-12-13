#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#define MOD 1e9+7
class Solution {
    public:
        int LongestRepeatingSubsequence(string str){
            vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,0));
            for(int i=1;i<=str.length();i++)
            {
                for(int j=1;j<=str.length();j++)
                {
                    if(str[i-1]==str[j-1] && i!=j)
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            return dp[str.length()][str.length()];
        }

};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends