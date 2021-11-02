// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {   int sum = accumulate(arr,arr+N,0);
        int dp[N+1][sum+1];
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(arr[i-1]>j)
                    {
                        dp[i][j] = dp[i-1][j]; 
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i-1]]+arr[i-1]);
                        if(2*dp[i][j]==sum)
                            return 1;
                    }
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends