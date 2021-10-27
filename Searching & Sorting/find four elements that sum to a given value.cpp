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
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        if(arr.size()<4){
            return ans;
        }
        if(arr.size()==4){
            if(accumulate(arr.begin(),arr.end(),0)==k){
                ans.push_back(arr);
                return ans;
            }else{
                return ans;
            }
        }
        // if(arr.empty()){
        //     return ans;
        // }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int target_2=k-arr[i]-arr[j];
                int left=j+1;
                int right=arr.size()-1;
                while(left<right){
                    int two_sum=arr[left]+arr[right];
                    if(two_sum==target_2){
                        vector<int> quadruplets;
                        quadruplets.push_back(arr[i]);
                        quadruplets.push_back(arr[j]);
                        quadruplets.push_back(arr[left]);
                        quadruplets.push_back(arr[right]);
                        ans.push_back(quadruplets);
                        while(left<right && arr[left]==quadruplets[2]){
                            left++;
                        }
                        
                        while(left<right && arr[right]==quadruplets[3]){
                            right--;
                        }
                    }else if(two_sum<target_2){
                        left++;
                    }else{
                        right--;
                    }
                }
                while(j+1<arr.size() && arr[j]==arr[j+1]){
                    j++;
                }
            }
            while(i+1<arr.size() && arr[i]==arr[i+1]){
                    i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        sort(a.begin(),a.end());
        rep(i,0,n)
            cout<<a[i]<<" ";
        newline;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends