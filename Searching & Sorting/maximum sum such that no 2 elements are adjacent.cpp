// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1);
        for(int i=0;i<n+1;i++)
        {
            if(i==0)
                dp[i]=0;
            else
            {
                if(i==1)
                {
                    dp[i]=arr[i-1];
                }
                else
                {
                    if(i==2)
                        dp[i]=max(arr[i-1],arr[i-2]);
                    else
                    {
                        dp[i]=max(dp[i-2]+arr[i-1],dp[i-1]); 
                    }
                }
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends