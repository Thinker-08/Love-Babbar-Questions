#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
#define int long long
void find(int power,vector<int> &v,vector<int> &prefix)
{
    int l=0,r=v.size()-1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(v[mid]>power)
            r=mid;
        else
            l=mid;
    }
    if(v[r]<=power)
        cout<<r+1<<" "<<prefix[r];
    else
        cout<<l+1<<" "<<prefix[l];
    newline;
}
int32_t main()
{
    fast;
    int n,q;
    cin>>n;
    vector<int> v(n),prefix(n);
    rep(i,0,n)
        cin>>v[i];
    sort(v.begin(),v.end());
    prefix[0]=v[0];
    for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+v[i];
    cin>>q;
    while(q--)
    {
        int p;
        cin>>p;
        find(p,v,prefix);
    }
    return 0;
}
