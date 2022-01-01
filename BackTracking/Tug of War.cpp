#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
vector<int> ans;
ll mini=INT_MAX;
void subset(vector<int> &v,vector<int> &temp,ll sum,int x,int idx)
{
    if(temp.size()==v.size()/2)
    {
        if(abs(sum-x-x)<mini)
        {
            ans=temp;
            mini=abs(sum-x-x);
        }
        return;
    }
    else{
        if(temp.size()<v.size()/2)
        {
            if(idx<v.size())
            {
                temp.push_back(v[idx]);
                subset(v,temp,sum,x+v[idx],idx+1);
                temp.pop_back();
                subset(v,temp,sum,x,idx+1);
            }
        }
    }
}
void subset1(vector<int> &v,vector<int>& temp,ll sum,ll x,int idx)
{
    if(temp.size()==(v.size()+1)/2)
    {
        if(abs(sum-x-x)<mini)
        {
            ans=temp;
            mini=abs(sum-x-x);
       }
        return;
    }
    else
    {
        if(temp.size()<(v.size()+1)/2)
        {
            if(idx<v.size())
            {
                temp.push_back(v[idx]);
                subset1(v,temp,sum,x+v[idx],idx+1);
                temp.pop_back();
                subset1(v,temp,sum,x,idx+1);
            }
        }
    }
}
void tests()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    ll sum=accumulate(v.begin(),v.end(),0);
    vector<int> temp,temp1;
    if(n%2==0)
        subset(v,temp,sum,0,0);
    else
        subset1(v,temp,sum,0,0);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
    newline;
}
int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        tests();
    }
    return 0;
}