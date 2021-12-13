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
bool shuffled(string a,string b)
{
    map<char,int> hasha,hashb;
    for(int i=0;i<a.length();i++)
    {
        hasha[a[i]]++;
    }
    for(int i=0;i<b.length();i++)
    {
        hashb[b[i]]++;
    }
    for(auto it=hashb.begin();it!=hashb.end();it++)
    {
        if(hasha[(*it).first]>=(*it).second)
            continue;
        else
            return false;
    }
    return true;
}
int main()
{
    fast;
    string a,b;
    cin>>a>>b;
    if(shuffled(a,b))
    {
        cout<<"YES";
    }
    else
        cout<<"NO";
    return 0;
}