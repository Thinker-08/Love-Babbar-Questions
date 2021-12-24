#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int maxSum(vector<int> &arr, int n) 
{
    vector<int> sum(n);
    if(n>=1)
    {
        sum[0]=arr[0];
    }
    if(n>=2)
    {
        sum[1]=sum[0]+arr[1];
    }
    if(n>2)
    {
        sum[2]=max(arr[0]+arr[1],max(arr[1]+arr[2],arr[0]+arr[2]));
    }
    for(int i=3;i<n;i++)
    {
        sum[i]=max(sum[i-1],max(sum[i-2]+arr[i],arr[i]+arr[i-1]+sum[i-3]));   
    }
    return sum[n-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int ans=maxSum(v,n);
    cout<<ans;
}