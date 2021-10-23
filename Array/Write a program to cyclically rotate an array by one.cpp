#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
void rotate(int arr[],int n)
{
    int temp,i;
    temp=arr[n-1];
    for(i=n-1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}
int main()
{
    bb;bb1;
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    rotate(arr,n);
    rep(i,0,n)
        cout<<arr[i]<<" ";
    return 0;
}