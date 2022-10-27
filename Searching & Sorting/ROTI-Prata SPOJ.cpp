#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
#define int long long
bool check(int maxi,vector<int> &v,int p)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        int val=1;
        for(int j=0;j<p;j++)
        {
            if(v[i]*(val*(val+1))/2<=maxi)
                val++;
            else
                break;
        }
        sum+=val-1;
        if(sum>=p)
            return true;
    }
    return false;
}
void tests()
{
    int p,l;
    cin>>p>>l;
    vector<int> v(l);
    rep(i,0,l)
        cin>>v[i];
    sort(v.begin(),v.end());
    int lo=1,hi = v[v.size()-1]*(p*(p+1))/2;
    while(lo<hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid,v,p))
            hi=mid;
        else
            lo=mid+1;
    }
    if(check(lo,v,p))
        cout<<lo;
    else
        cout<<hi;
    newline;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        tests();
}
