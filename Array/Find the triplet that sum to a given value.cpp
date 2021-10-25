#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
bool find3Numbers(int arr[], int n, int X)
{
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]+mp[arr[j]]+arr[i]==X)
            {
                return true;
            }
            else
            {
                mp[X-(arr[j]+arr[i])]=arr[j];
            }
        }
    }
    return false;
}
int main()
{
    fast;
    int n,x;
    cin>>n>>x;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    if(find3Numbers(arr,n,x))
        cout<<1;
    else
        cout<<0;
    return 0;
}