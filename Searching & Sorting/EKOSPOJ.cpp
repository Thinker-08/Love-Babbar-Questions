#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
bool check(vector<int>&v,int h,int maxi)
{
    ll sum=0;
    for(int i=0;i<v.size();i++)
    {
        if(h<=v[i])
            sum = sum + v[i]-h;
    }
    if(sum>=maxi)
        return true;
    else
        return false;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    sort(v.begin(),v.end());
    ll hi=2*1e9,lo=0;
    int mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(check(v,mid,m))
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(check(v,hi,m))
        cout<<hi;
    else
        cout<<lo;
    return 0;
}