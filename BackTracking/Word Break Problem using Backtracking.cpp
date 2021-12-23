// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
    bool check(vector<string> &dict,string test)
    {
        for(int i=0;i<dict.size();i++)
        {
            if(dict[i].compare(test)==0)
            {
                return true;
            }
        }
        return false;
    }
    void driver(vector<string> &dict,string s,int idx,string temp)
    {
        if(idx==s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.length();i++)
        {
            if(check(dict,s.substr(idx,i-idx+1)))
            {
                if(i+1==s.length())
                    driver(dict,s,i+1,temp+s.substr(idx,i-idx+1));
                else
                    driver(dict,s,i+1,temp+s.substr(idx,i-idx+1)+" ");
            }
        }
        return;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        driver(dict,s,0,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends