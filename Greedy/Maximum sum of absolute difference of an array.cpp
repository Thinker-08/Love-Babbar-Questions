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
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<int> one,two;
    rep(i,0,n/2)
    {
        one.push_back(v[i]);
    }
    rep(i,n/2,n)
    {
        two.push_back(v[i]);
    }
    int j=0,k=0;
    sort(two.begin(),two.end(),greater<int>());
    rep(i,0,n)
    {
        if(i%2==0)
        {
            v[i]=one[j];
            j++;
        }
        else
        {
            v[i]=two[k];
            k++;
        }
    }
    int sum=0;
    rep(i,0,n-1)
    {
        sum=sum+abs(v[i+1]-v[i]);
    }
    sum=sum+abs(v[n-1]-v[0]);
    cout<<sum;
    return 0;
}