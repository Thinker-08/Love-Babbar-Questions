// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(int arr[],int start,int end,vector<long long> &v1)
  {
      for(int i=0;i<(1<<(end-start));i++)
      {
          int j=start;
          int x=i;
          long long prod=1;
          while(x)
          {
                int temp=(x&1);
                if(temp)
                {
                    prod=prod*arr[j];   
                }
                j++;
                x=x>>1;
          }
          v1.push_back(prod);
        }
  }
    int numOfSubsets(int arr[], int N, int K)
    {
        int count=0;
        vector<long long> v1,v2;
        solve(arr,0,N/2,v1);
        solve(arr,N/2,N,v2);
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++)
        {
            int high=upper_bound(v2.begin(),v2.end(),K/v1[i])-v2.begin();
            count=count+high;
        }
        return --count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends