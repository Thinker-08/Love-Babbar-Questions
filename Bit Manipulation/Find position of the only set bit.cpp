// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N)
    {
        int temp=INT_MAX,j=0;
        while(N)
        {
            int t=(N&1);
            if(t)
            {
                if(temp==INT_MAX)
                    temp=j+1;
                else
                    return -1;
            }
            j++;
            N=N>>1;
        }
        return temp==INT_MAX?-1:temp;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends