// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s)
		{
		    vector<int> mp(26,0);
		    set<pair<int,char>> st;
		    string ans;
		    for(int i=0;i<s.length();i++)
		    {
		        if(st.empty())
		        {
		            mp[s[i]-'a']++;
		            ans+=s[i];
		            st.insert({i,s[i]});
		        }
		        else
		        {
		            if(mp[s[i]-'a']==0)
		                st.insert({i,s[i]});
		            mp[s[i]-'a']++;
		            int flag=0;
		            for(auto it=st.begin();it!=st.end();it++)
		            {
		                if(mp[(it->second)-'a']==1)
		                {
		                    flag=1;
		                    ans+=it->second;
		                    break;
		                }
		            }
		            if(!flag)
		                ans+='#';
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends