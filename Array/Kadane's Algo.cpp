#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=sum+v[i];
        maxi=max(sum,maxi);
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<maxi;
    return 0;
}