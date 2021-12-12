// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s)
    {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for(int k=0;k<s.length();k++)
        {
            for(int i=0,j=k;j<s.length();i++,j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else
                {
                    if(abs(j-i)==1)
                    {
                        if(s[i]==s[j])
                            dp[i][j]=2;
                        else
                        {
                            dp[i][j]=1;
                        }
                    }
                    else
                    {
                        if(s[i]==s[j])
                            dp[i][j]=dp[i+1][j-1]+2;
                        else
                        {
                            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                        }
                    }
                }
            }
        }
        return (s.length()-dp[0][s.length()-1]);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends