#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int fun(int arr[],int N)
{
    if(N==1)
            return 1;
        else
        {
            int count=1;
      sort(arr,arr+N);
      map<int,int> mp;
      for(int i=0;i<N;i++)
      {
            mp[arr[i]]++;
      }
      vector<int> v;
      for(auto it=mp.begin();it!=mp.end();it++)
      {
          v.push_back((*it).first);
      }
      int x=v[0],maxi=INT_MIN;
    for(int i=1;i<v.size();i++)
    {
        if(x+1==v[i])
        {
            count++;
        }
        else
        {
            count=1;
        }
        maxi=max(maxi,count);
        x=v[i];
    } 
    return maxi;   
}
int main()
{
    fast;
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    int a = fun(arr,n);
    cout<<a;
    return 0;
}