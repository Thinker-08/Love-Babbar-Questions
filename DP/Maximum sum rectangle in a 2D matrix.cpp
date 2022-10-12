//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans=INT_MIN;
        for(int k=0;k<R;k++)
        {
            vector<int> v(C,0);
            for(int i=k;i<R;i++)
            {
                int sum=0;
               for(int j=0;j<C;j++)
               {
                    v[j]+=M[i][j];
                    sum=max(v[j],sum+v[j]);
                    ans=max(ans,sum);
               }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends