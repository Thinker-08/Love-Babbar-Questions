#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        if(v[i]<v[i+1])
            break;
    }
    int min = v[i];
    map<int,int> mp;
    for(int j=n-1;j>i;j--)
    {
        if(v[j]>min)
        {
            mp[v[j]]=j;
        }
    }
    swap(v[(*mp.begin()).second],v[i]);
    reverse(v.begin()+i+1,v.end());
    rep(i,0,v.size())
        cout<<v[i]<<" ";
    return 0;
}