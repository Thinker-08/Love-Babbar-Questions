#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> kLargest(int arr[], int n, int k) {
        vector<int> v;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            pq.push(arr[i]);
        for(int i=0;i<k;i++)
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    int arr[n];
    rep(i,0,n)
        cin>>arr[i];
    vector<int> v=kLargest(arr,n,k);
    rep(i,0,v.size())
        cout<<v[i]<<" ";
    return 0;
}