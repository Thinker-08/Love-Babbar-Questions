#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans;
        int maxi,mini,largest=arr[n-1]-k,smallest=arr[0]+k;
        ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++)
        {
            mini=min(smallest,arr[i+1]-k);
            maxi=max(largest,arr[i]+k);
            if(mini<0)
                continue;
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends6