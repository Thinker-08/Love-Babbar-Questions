// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int driver(vector<vector<int>>&M,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>=M.size() || j>=M[0].size())
            return 0;
        if(j==M[0].size()-1)
            return M[i][j];
        if(dp[i][j]==-1)
        {
            dp[i][j]=max(driver(M,i+1,j+1,dp),max(driver(M,i,j+1,dp),driver(M,i-1,j+1,dp)))+M[i][j];
        }
        return dp[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxi=INT_MIN;
        const int N=1e3;
        vector<vector<int>> dp(N,vector<int> (N,-1));
        for(int i=0;i<M.size();i++)
        {
            maxi=max(maxi,driver(M,i,0,dp));
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends