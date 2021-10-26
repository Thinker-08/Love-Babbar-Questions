#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> max_of_subarrays(int *arr,int n,int k)
{
    vector<int> v;
    priority_queue<pair<int,int>> pq;
    rep(i,0,n)
    {
        while(!pq.empty() && pq.top().second<=(i-k))
        {
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        if(i>=k-1)
            v.push_back(pq.top().first);
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
    vector<int> v=max_of_subarrays(arr,n,k);
    rep(i,0,v.size())
        cout<<v[i]<<" ";
    return 0;
}