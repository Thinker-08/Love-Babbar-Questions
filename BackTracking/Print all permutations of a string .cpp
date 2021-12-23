// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
	    void permute(string s,int i)
	    {
	        if(i==s.length())
            {
                ans.push_back(s); 
                return;
            }
            for(int j=i;j<s.length();j++)
            {
                swap(s[j],s[i]);
                permute(s,i+1);
                swap(s[j],s[i]);
            }
            return;
	    }
		vector<string>find_permutation(string S)
		{
		    permute(S,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends