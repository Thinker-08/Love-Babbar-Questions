#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#define MOD 1e9+7
void solve(ll st,ll end,vector<ll> &v1,vector<ll>&v)
{
    ll sum=0;
    for(ll i=0;i<(1<<(end-st+1));i++)
    {
        sum=0;
        ll j=st;
        ll x=i;
        while(x)
        {
            int temp=(x&1);
            if(temp)
            {
                sum=sum+v[j];
            }
            j++;
            x=x>>1;
        }
        v1.push_back(sum);
    }
}
int main()
{
    fast;
    ll n,a,b,ans=0;
    cin>>n>>a>>b;
    vector<ll> v;
    rep(i,0,n)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<ll> v1,v2;
    solve(0,n/2-1,v1,v);
    solve(n/2,n-1,v2,v);
    sort(v2.begin(),v2.end());
    for(ll i=0;i<v1.size();i++)
    {
        ll low=lower_bound(v2.begin(),v2.end(),a-v1[i])-v2.begin();
        ll high=upper_bound(v2.begin(),v2.end(),b-v1[i])-v2.begin();
        ans+=high-low;
    }
    cout<<ans;
    return 0;
}