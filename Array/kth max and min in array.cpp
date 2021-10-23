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
    int n,k;
    cin>>n>>k;
    int arr[n];
    rep(i,0,n)
        cin>>arr[i];
    sort(arr,arr+n);
    cout<<"kth Maximum: "<<arr[n-k];
    cout<<"\nkth Minimum: "<<arr[k-1];
    return 0;
}