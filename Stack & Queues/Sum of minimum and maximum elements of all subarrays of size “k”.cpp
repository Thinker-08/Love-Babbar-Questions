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
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.first > b.first;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    priority_queue<pair<int,int>> pqmaxi;
    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pqmini;
    int i=0,j=0,sum=0;
    while(i<n and j<n)
    {
        pqmaxi.push(make_pair(arr[j],j));
        pqmini.push(make_pair(arr[j],j));
        if(j-i+1<k)
            j++;
        else
        {
            sum=sum+pqmaxi.top().first+pqmini.top().first;
            while(!pqmaxi.empty() and pqmaxi.top().second<=i)
            {
                pqmaxi.pop();
            }
            while(!pqmini.empty() and pqmini.top().second<=i)
            {
                pqmini.pop();
            }
            i++;
            j++;
        }
    }
    cout<<sum;
}