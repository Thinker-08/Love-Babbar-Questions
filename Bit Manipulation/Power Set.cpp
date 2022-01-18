// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<string> ans;
	void driver(string s,int idx,string temp)
	{
	    if(idx==s.length())
	    {
	        ans.push_back(temp);
	        return;
	    }
        driver(s,idx+1,temp+s[idx]);
        driver(s,idx+1,temp);
	}
	vector<string> AllPossibleStrings(string s){
	    string temp;
	    driver(s,0,temp);
	    sort(ans.begin(),ans.end());
	    ans.erase(ans.begin());
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends