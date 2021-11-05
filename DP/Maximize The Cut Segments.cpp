// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int maxi=x;
        if(maxi>y)
        {
            if(maxi>z)
                ;
            else
                maxi=z;
        }
        else
        {
            maxi=y;
            if(maxi>z)
                ;
            else
                maxi=z;
        }
        vector<int> dp(n+1+maxi);
        for(int i=0;i<n+1;i++)
            dp[i]=-1;
        dp[0]=0;
        for(int i=0;i<n+1;i++)
        {
            if(dp[i]!=-1)
            {   
                dp[i+x] = max(dp[i+x],dp[i]+1);
                dp[i+y] = max(dp[i+y],dp[i]+1);
                dp[i+z] = max(dp[i+z],dp[i]+1);
            }
        }
        if(dp[n]==-1)
            return 0;
        else
            return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends