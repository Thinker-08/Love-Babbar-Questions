// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  vector<vector<string>> ans;
    bool ispalin(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
    void driver(string s,int start,vector<string> cur_v)
    {
        if(start>=s.length())
        {
            ans.push_back(cur_v);
            return;
        }
        else
        {
            for(int i=start;i<s.length();i++)
            {
                if(ispalin(s,start,i))
                {
                    cur_v.push_back(s.substr(start,i-start+1));
                    driver(s,i+1,cur_v);
                    cur_v.pop_back();
                }
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s)
    {
        vector<string> temp;
        driver(s,0,temp);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends