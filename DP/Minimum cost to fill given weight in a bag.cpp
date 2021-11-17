// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<int> val,wt;
        for(int i=0;i<N;i++)
        {
            if(cost[i]<0)
                ;
            else
            {
                val.push_back(cost[i]);
                wt.push_back(i+1);
            }
        }
        int dp[val.size()+1][W+1];
        for(int i=0;i<val.size()+1;i++)
        {
            for(int j=0;j<W+1;j++)
            {
                if(j==0)
                    dp[i][j]=0;
                else
                {
                    if(i==0)
                        dp[i][j]=1e5;
                    else
                    {
                        if(wt[i-1]<=j)
                        {
                            dp[i][j]=min(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
                        }
                        else
                        {
                            dp[i][j]=dp[i-1][j];
                        }
                    }
                }
            }
        }
        return dp[val.size()][W]!=1e5 ? dp[val.size()][W]:-1;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends