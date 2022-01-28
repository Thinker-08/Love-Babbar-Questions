// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int ones=0,zeros=0;
	    int maxi=0,diff;
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='0')
	            zeros++;
	        else
	            ones++;
	        diff=zeros-ones;
	        if(diff<0)
	        {
	            diff=0;
	            ones=0;
	            zeros=0;
	        }
	        else
	            maxi=max(maxi,diff);
	    }
	    return maxi==0?-1:maxi;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends