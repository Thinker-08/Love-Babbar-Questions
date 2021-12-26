#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int countCustomers(vector<int> &arr, int k)
{
    int ans=0;
    const int N=1e6;
    vector<int> mp(N,0);
    for(int i=0;i<arr.size();i++)
    {
        if(mp[arr[i]]==-1)
            continue;
        if(mp[arr[i]]==0)
        {
            if(k==0)
            {
                mp[arr[i]]=-1;
                ans++;
                continue;
            }
            mp[arr[i]]=1;
            k--;
        }
        else
        {
            k++;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        rep(i,0,n)
            cin>>v[i];
        int ans=countCustomers(v,k);
        cout<<ans<<endl;
    }
}