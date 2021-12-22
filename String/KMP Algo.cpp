// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    vector<int> prefix_fun(string s)
    {
        vector<int> prefix(s.length(),0);
        for(int i=0;i<s.length();i++)
        {
            if(i==0)
                prefix[i]=0;
            else
            {
                int j=prefix[i-1];
                while(j>0 and s[i]!=s[j])
                    j = prefix[j-1];
                if(s[i]==s[j])
                    j++;
                prefix[i]=j;
            }
        }
        return prefix;
    }
    vector<int>search(string pat, string txt)
    {
        vector<int> prefix=prefix_fun(txt);
        vector<int> ans;
        int pos=-1,i=0,j=0;
        while(i<txt.length())
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                {
                    j=prefix[j-1];
                }
                else
                {
                    i++;
                }
            }
            if(j==pat.length())
            {
                ans.push_back(i-pat.length()+1);
            }
        }
        return ans;
    }   
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends