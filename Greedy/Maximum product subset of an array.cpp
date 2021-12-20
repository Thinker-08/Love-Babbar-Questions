#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#define MOD 1e9+7
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    priority_queue<int,vector<int>> pq;
    for(int i=1;i<(1<<(v.size()));i++)
    {
        int x=i;
        int j=0;
        int product=1;
        while(x)
        {
            int temp=(x&1);
            if(temp)
                product=product*v[j];
            j++;
            x=x>>1;
        }
        pq.push(product);
    }
    cout<<pq.top();
    return 0;
}