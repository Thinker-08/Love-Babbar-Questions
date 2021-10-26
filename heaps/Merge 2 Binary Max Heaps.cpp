#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        priority_queue<int> pq;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            pq.push(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            pq.push(b[i]);
        }
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    rep(i,0,n)
        cin>>a[i];
    rep(i,0,m)
        cin>>b[i];
    vector<int> v = mergeHeaps(a,b,n,m);
    rep(i,0,v.size())
        cout<<v[i]<<" ";
}