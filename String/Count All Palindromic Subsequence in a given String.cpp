// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
long long dp[str.length()][str.length()];
        for(int i=0;i<str.length();i++)
        {
            for(int j=0;j<str.length();j++)
            {
                if(i>j)
                    dp[i][j]=0;
            }
        }
        for(int k=0;k<str.length();k++)
        {
            for(int i=0,j=k;i<str.length()-k;i++,j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else
                {
                    if(str[i]==str[j])
                        dp[i][j]=(dp[i+1][j]+dp[i][j-1]+1)%1000000007;
                    else
                        dp[i][j]=(dp[i+1][j]+dp[i][j-1]+1000000007-dp[i+1][j-1])%1000000007;

                }
            }
        }
        return dp[0][str.length()-1]%1000000007;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends