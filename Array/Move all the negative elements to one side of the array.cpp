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
    int n,k,z,o,t;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);  
    rep(i,0,n)
        cout<<arr[i]<<" ";
    return 0;
}