//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void getall(string s,int idx,int count,string temp,vector<string> &ans)
    {
        if(idx>=s.length())
            return;
        if(count==0)
        {
            string x=temp;
            int cc=0;
            if(s[idx]=='0' and s.length()-idx>1)
                return;
            for(int i=idx;i<s.length();i++)
            {
                x+=s[i];
                cc=cc*10+(s[i]-'0');
                if(cc>255)
                    return;
            }
            if(cc<=255)
                ans.push_back(x);
            return;
        }
        int cc=0;
        string x;
        for(int i=idx;i<s.length();i++)
        {
            x+=s[i];
            cc=cc*10+(s[i]-'0');
            if(x[0]=='0')
            {
                if(x.length()==1)
                {
                    getall(s,i+1,count-1,temp+x+'.',ans);
                    continue;
                }
                else
                    return;
            }
            if(cc>255)
                return;
            if(cc<=255)
                getall(s,i+1,count-1,temp+x+'.',ans);
        }
    }
    vector<string> genIp(string &s) {
        if(s.length()<4)
            return {};
        string temp;
        vector<string> ans;
        getall(s,0,3,temp,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends