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
    map<int,int> mp;
    rep(i,0,n)
    {
        cin>>v[i];
        mp[v[i]]+=1;
    }    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if((*it).second==2)
        {
            cout<<(*it).first;
            break;
        }
    }
    return 0;
}