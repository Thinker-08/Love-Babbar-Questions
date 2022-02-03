// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool isInterleave(string A, string B, string C) 
    {
        if(C.length()!=A.length()+B.length())
            return false;
        else
        {
            vector<vector<bool>> dp(A.length()+1,vector<bool> (B.length()+1,false));
            for(int i=0;i<=A.length();i++)
            {
                for(int j=0;j<=B.length();j++)
                {
                    if(i==0 and j==0)
                        dp[i][j]=true;
                    else
                    {
                        if(i==0)
                        {
                            if(B[j-1]==C[j-1])
                                dp[i][j]=dp[i][j-1];
                        }
                        else 
                        {
                            if(j==0)
                            {
                                if(A[i-1]==C[i-1])
                                    dp[i][j]=dp[i-1][j];
                            }
                            else
                            {
                                if(A[i-1]==C[i+j-1] and B[j-1]!=C[i+j-1])
                                    dp[i][j]=dp[i-1][j];
                                else
                                {
                                    if(A[i-1]!=C[i+j-1] and B[j-1]==C[i+j-1])
                                        dp[i][j] = dp[i][j-1];
                                    else if(A[i-1]==C[i+j-1] and B[j-1]==C[i+j-1])
                                        dp[i][j] = dp[i-1][j] or dp[i][j-1];
                                }
                            }
                        }
                    }
                }
            }
            return dp[A.length()][B.length()];
        }
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends