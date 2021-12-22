// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        vector<vector<bool>> palin(str.length(),vector<bool> (str.length()));
        vector<int>checks(str.length());
        for(int i=0;i<str.length();i++)
        {
            palin[i][i]=true;
        }
        for(int k=0;k<str.length();k++)
        {
            for(int i=0,j=k;i<str.length() and j<str.length();i++,j++)
            {
                if(i==j)
                    palin[i][j]=true;
                else
                {
                    if(abs(j-i)==1)
                    {
                        if(str[i]==str[j])
                            palin[i][j]=true;
                        else
                            palin[i][j]=false;
                    }
                    else
                    {
                        if(str[i]==str[j] and palin[i+1][j-1]==true)
                        {
                            palin[i][j]=true;
                        }
                        else
                        {
                            palin[i][j]=false;
                        }
                    }
                }
            }
        }
        for(int i=0;i<str.length();i++)
        {
            if(palin[0][i]==true)
                checks[i]=0;
            else
            {
                checks[i]=INT_MAX;
                for(int j=0;j<i;j++)
                {
                    if(palin[j+1][i]==true and 1+checks[j]<checks[i])
                        checks[i]=1+checks[j];
                }
            }
        }
        return checks[str.length()-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends