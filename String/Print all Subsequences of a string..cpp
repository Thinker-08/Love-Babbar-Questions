#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution {
  public:
        vector<string> v;
        void allsubs (string S,int i,string ans) 
        {
            if(i==S.length())
            {
                v.push_back(ans);
                return;
            }
            allsubs(S,i+1,ans);
            ans=ans+S[i];
            allsubs(S,i+1,ans);
        }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        ob.allsubs(S,0,"");
        rep(i,0,ob.v.size())
        {
            cout<<ob.v[i];
            newline;
        }
    }
    return 0;
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends