// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long nCr(int n, int r){
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
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%1000000007;
                }
            }
        }
    }
    return dp[r][n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends