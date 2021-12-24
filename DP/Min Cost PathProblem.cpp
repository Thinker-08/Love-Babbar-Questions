// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    static const int m=1e3;
    int driver(vector<vector<int>> &Matrix,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>=Matrix.size() || j>=Matrix[0].size())  
        {
            return 0;   
        }
        if(i==Matrix.size()-1)
        {
            return Matrix[i][j];
        }
        if(dp[i][j]==-1)
        {
            dp[i][j]=max(driver(Matrix,i+1,j,dp),
            max(driver(Matrix,i+1,j+1,dp),
            driver(Matrix,i+1,j-1,dp)))+Matrix[i][j];   
        }
        return dp[i][j];
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        const int m=1e3;
        vector<vector<int>> dp(m,vector<int> (m,-1));
        int maxi=INT_MIN;
        for(int i=0;i<Matrix[0].size();i++)
        {
            maxi=max(driver(Matrix,0,i,dp),maxi);
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends