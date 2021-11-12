// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string ans;
        for(int i=0;i<S.length()-1;i++)
        {
            if(S[i]==S[i+1])
                continue;
            else
                ans=ans+S[i];
        }
        if(S[S.length()-1]==S[S.length()-2])
            return ans+S[S.length()-2];
        else
            ans=ans+S[S.length()-1];
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends