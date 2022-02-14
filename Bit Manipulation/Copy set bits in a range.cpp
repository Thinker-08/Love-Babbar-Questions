// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setAllRangeBits(int N , int L , int R)
    {
        int ans = 1<<R-L+1;
        ans--;
        ans=ans<<(L-1);
        return N|ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.setAllRangeBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends