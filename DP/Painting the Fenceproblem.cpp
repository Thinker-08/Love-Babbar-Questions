// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k)
    {
        vector<long long> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                dp[i]=k;
            else
            {
                if(i==2)
                    dp[i]=k*k;
                else
                {
                    dp[i]=((k-1)*(dp[i-1]+dp[i-2]))%1000000007;
                }
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends