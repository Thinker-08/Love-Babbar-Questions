#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int main()
{
    fast;
    string s;
    cin>>s;
    int zeros=0,ones=0,ans=0;
    rep(i,0,s.length())
    {
        if(s[i]=='0')
            zeros++;
        else
            ones++;
        if(zeros==ones)
            ans++;
    }
    if(ans!=0)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}