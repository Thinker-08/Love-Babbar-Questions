// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    static bool cmp(pair<int,string> a,pair<int,string> b)
    {
        return a.first>b.first;
    }
    string secFrequent (string arr[], int n)
    {
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=mp[arr[i]]+1;
        }
        vector<pair<int,string>> v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v.push_back(make_pair((*it).second,(*it).first));
        }
        sort(v.begin(),v.end(),cmp);
        int maxi=v[0].first;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first<maxi)
                return v[i].second;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends