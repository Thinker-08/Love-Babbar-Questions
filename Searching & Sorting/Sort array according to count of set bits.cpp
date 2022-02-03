// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[__builtin_popcount(arr[i])].push_back(i);
        }
        vector<int> new_arr;
        for(auto it=--mp.end();it!=mp.begin();it--)
        {
            sort((*it).second.begin(),(*it).second.end());
            for(int i=0;i<(*it).second.size();i++)
            {
                new_arr.push_back(arr[(*it).second[i]]);   
            }
        }
        sort((*mp.begin()).second.begin(),(*mp.begin()).second.end());
        for(int i=0;i<(*mp.begin()).second.size();i++)
            new_arr.push_back(arr[(*mp.begin()).second[i]]);
        for(int i=0;i<new_arr.size();i++)
            arr[i]=new_arr[i];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends