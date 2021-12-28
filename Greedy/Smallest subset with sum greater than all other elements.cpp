#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int minisize(vector<int> &v)
{
    sort(v.begin(),v.end());
    int ans=0,j=v.size()-1,summ=accumulate(v.begin(),v.end(),0);
    int temp=v[v.size()-1];
    while(summ>=temp)
    {
        summ=summ-v[j];
        j--;
        ans++;
    }
    return ans;
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
    {
        cin>>v[i];
    }
    int ans=minisize(v);
    cout<<ans;
    return 0;
}