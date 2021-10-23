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
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int cur=0,maxi=INT_MIN;
    rep(i,0,n)
    {
        cur=cur+v[i];
        maxi = max(cur,maxi);
        if(cur<0)
            cur=0;
    }
    cout<<maxi;
}