#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long long dp[n+1];
        for(int i=0;i<n+1;i++)
        {
            if(i<=2)
                dp[i]=i;
            else
            {
                dp[i]=(dp[i-1]+(i-1)*dp[i-2])%1000000007;
            }
        }
        return dp[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout <<ob.countFriendsPairings(n); 
        cout<<endl;
    }
} 
  // } Driver Code Ends