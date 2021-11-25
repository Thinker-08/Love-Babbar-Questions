// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int d=256;
            vector<int>v;
            int m=pat.length(),n=txt.length(),q=101;
            int h=1;
            for(int i=0;i<m-1;i++){
                h=(h*d)%q;
            }
            int p=0,t=0;
            for(int i=0;i<m;i++){
               p=(d*p+pat[i])%q;
               t=(d*t+txt[i])%q;
            }
            for(int i=0;i<=n-m;i++){
                if(p==t){
                    int j=0;
                    for(j=0;j<m;j++){
                        if(pat[j]!=txt[i+j])
                          break;
                    }
                    if(j==m)
                      v.push_back(i+1);
                }
                if(i<n-m)
                {
                    t=(d*(t-txt[i]*h)+txt[i+m])%q;
                    if(t<0)
                      t=t+q;
                }
            }
            if(v.empty())
               v.push_back(-1);
          return v; 
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