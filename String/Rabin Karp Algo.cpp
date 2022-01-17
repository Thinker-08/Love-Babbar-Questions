// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 class Solution
{
    public:
        vector <int> search(string pat, string s)
        {
            vector<int> ans;
            vector<long long> powers(1e5+7,0);
            powers[0]=1;
            for(int i=1;i<1e5+7;i++)
            {
                powers[i]=(powers[i-1]*27)%1000000007;
            }
            vector<long long> hash(s.size()+1,0);
            for(int i=0;i<s.size();i++)
            {
                hash[i+1]=(hash[i]+((s[i]-'a'+1)*powers[i]))%1000000007;
            }
            long long temp=0;
            for(int i=0;i<pat.length();i++)
            {
                temp=(temp+((pat[i]-'a'+1)*powers[i]))%1000000007;
            }   
            for(int i=0;i+pat.length()-1<s.length();i++)
            {
                long long cur=0;
                cur=(hash[i+pat.length()]-hash[i]+1000000007)%1000000007;
                if(cur==(temp*powers[i])%1000000007)
                    ans.push_back(i+1);
            }
            if(ans.empty())
            {
                ans.push_back(-1);
                return ans;
            }
            else
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
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends