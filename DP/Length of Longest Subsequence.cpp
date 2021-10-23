#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N=1e5;
vector<int> v;
int main()
{
    int n;
    cin>>n;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> dp(n,1);
    int ans=0;
    rep(i,1,n)
    {
        rep(j,0,i)
        {
            if(v[j]<v[i])
                dp[i] = max(dp[i],1+dp[j]);
            ans = max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}