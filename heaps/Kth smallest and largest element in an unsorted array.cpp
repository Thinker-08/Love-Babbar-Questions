#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int ksmallest(int arr[], int n, int k)
{
        priority_queue<int,vector<int>,greater<int>> pq;
        rep(i,0,n)
            pq.push(arr[i]);
        rep(i,0,k-1)
            pq.pop();
        return pq.top();
    }
int klargest(int arr[],int n,int k)
{
    priority_queue<int> pq;
    int ans;
    rep(i,0,n)
        pq.push(arr[i]);
    rep(i,0,k)
        pq.pop();
    return pq.top();
}
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    int arr[n];
    rep(i,0,n)
        cin>>arr[i];
    sort(arr,arr+n);
    rep(i,0,n)
        cout<<arr[i]<<" ";
    int l = klargest(arr,n,k);
    int s = ksmallest(arr,n,k);
    cout<<"Smallest: "<<s;
    newline;
    cout<<"Largest: "<<l;
}