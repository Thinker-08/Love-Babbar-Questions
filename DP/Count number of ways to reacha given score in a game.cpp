// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
    vector<int> arr;
    arr.push_back(3);arr.push_back(5);arr.push_back(10);
    vector<vector<int>> dp(4,vector<int>(n+1,0));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            else
            {
                if(j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    if(arr[i-1]<=j)
                    {
                        dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
    }
    return dp[3][n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends