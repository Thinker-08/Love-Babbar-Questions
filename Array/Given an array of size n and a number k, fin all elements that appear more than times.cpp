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
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        mp[temp]+=1;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if((*it).second>n/k)
            cout<<"Number: "<<(*it).first<<"  count: "<<(*it).second<<endl;
    }
    return 0;
}