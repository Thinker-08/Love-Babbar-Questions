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
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[arr[i]]++;
    
        int twice_count = 0;
        for (int i = 0; i < n; i++) {
            twice_count += m[k - arr[i]];
            if (k - arr[i] == arr[i])
                twice_count--;
        }
        return twice_count / 2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends