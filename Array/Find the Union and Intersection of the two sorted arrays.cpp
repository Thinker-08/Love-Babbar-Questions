#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
int main()
{
    bb;bb1;
    int n,k,z,o,t;
    map<int,int> mp;
    cin>>n>>k;
    int arr1[n],arr2[k];
    rep(i,0,n)
    {
        cin>>arr1[i];
        if(mp[arr1[i]]==0)
            mp[arr1[i]]=1;
    }
    rep(i,0,k)
    {
        cin>>arr2[i];
        if(mp[arr2[i]]==0)
            mp[arr2[i]]=1;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<(*it).first<<" ";
    }
    return 0;
}