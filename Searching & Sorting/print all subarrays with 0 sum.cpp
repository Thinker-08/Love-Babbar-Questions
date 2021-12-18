// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, ll n )
    {
        unordered_map<ll,vector<ll>> mp;
        ll sum=0,ans=0;
        for(ll i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum==0)
            {
                ans++;
            }
            if(mp.find(sum)!=mp.end())
            {
                ans=ans+mp[sum].size();
            }
            mp[sum].push_back(i);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends