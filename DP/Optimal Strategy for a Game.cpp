// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maximumAmount(int arr[], int n)
    {
        vector<vector<long long>> dp(n,vector<long long>(n));
        for(int k=0;k<n;k++)
        {
            for(int i=0,j=k;i<n and j<n;j++,i++)
            {
                long long a=(i+2<=j)?dp[i+2][j]:0;
                long long b=(i+1<=j-1)?dp[i+1][j-1]:0;
                long long c=(i<=j-2)?dp[i][j-2]:0;
                dp[i][j] = max(arr[i]+min(a,b),arr[j]+min(b,c));
            }
        }
        return dp[0][n-1];
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends