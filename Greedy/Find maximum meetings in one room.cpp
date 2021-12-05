#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution
{
    public:
    static bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
    {
        return a.second.second<b.second.second;
    }
    vector<int> maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,pair<int,int>>> v;
        rep(i,0,n) 
            v.push_back(make_pair(i+1,make_pair(start[i],end[i])));
        sort(v.begin(),v.end(),cmp);
        vector<int> final;
        final.push_back(1);
        int cur=v[0].second.second;
        for(int i=1;i<n;i++)
        {
            if(cur<v[i].second.first)
            {
                cur=v[i].second.second;
                final.push_back(v[i].first);
            }
        }
        return final;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        vector<int> ans = ob.maxMeetings(start, end, n);
        rep(i,0,ans.size())
        {
            cout<<ans[i]<<" ";
        }
        newline;
    }
    return 0;
}  // } Driver Code Ends