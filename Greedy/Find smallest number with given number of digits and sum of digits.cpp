// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D)
    {
        if(S>9*D)
            return "-1";
        vector<int> v(D);
        S-=1;
        for(int i=D-1;i>0;i--)
        {
            if(S>9)
            {
                v[i]=9;
                S-=9;
            }
            else
            {
                v[i]=S;
                S=0;
            }
        }
        v[0]=S+1;
        string ans="";
        for(int i=0;i<D;i++)
            ans+=to_string(v[i]);
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends