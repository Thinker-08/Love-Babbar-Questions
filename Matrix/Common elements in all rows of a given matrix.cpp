// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_map<int,int> mp_A,mp_B,mp_C,mp;
            for(int i=0;i<n1;i++)
            {
                if(mp_A[A[i]]==0)
                    mp_A[A[i]]=1;
            }
            for(int i=0;i<n2;i++)
            {
                if(mp_B[B[i]]==0)
                    mp_B[B[i]]=1;
            }
            for(int i=0;i<n3;i++)
            {
                if(mp_C[C[i]]==0)
                    mp_C[C[i]]=1;
            }
            for(auto it=mp_B.begin();it!=mp_B.end();it++)
            {
                mp_A[(*it).first]+=1;
            }
            for(auto it=mp_C.begin();it!=mp_C.end();it++)
            {
                mp_A[(*it).first]+=1;
            }
            vector<int> ans;
            for(auto it=mp_A.begin();it!=mp_A.end();it++)
            {
                if((*it).second==3)
                    ans.push_back((*it).first);
            }
            sort(ans.begin(),ans.end());
            return ans;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends