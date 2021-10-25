#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size())
        {
            vector<int> a;
            int x=intervals[i][0],y=intervals[i][1];
            while(y>=intervals[i][0])
            {
                if(y>=intervals[i][0])
                {
                    if(y>=intervals[i][1])
                        ;
                    else
                        y=intervals[i][1];
                }
                else
                {
                    i++;
                    break;
                }
                i++;
                if(i<intervals.size())
                    continue;
                else
                    break;
            }
            a.push_back(x);
            a.push_back(y);
            ans.push_back(a);
        }
        return ans;
    }
int main()
{
    fast;
    int n;
    cin>>n;
    vector<vector<int>> v;
    rep(i,0,n)
    {
        int x,y;
        cin>>x>>y;
        vector<int> a;
        a.push_back(x);
        a.push_back(y);
        v.push_back(a);
    }
    vector<vector<int>> ans = merge(v);
    rep(i,0,ans.size())
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<'\n';
    }
    return 0;
}