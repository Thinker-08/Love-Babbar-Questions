#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int32_t main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    rep(i,0,n)
        cin>>a[i];
    rep(i,0,m)
        cin>>b[i];
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int hori=1,vert=1;
    int i=0,j=0,ans=0;
    while(i<n and j<m)
    {
        if(a[i]>b[j])
        {
            ans+=hori*a[i];
            i++;
            vert++;
        }
        else
        {
            ans+=vert*b[j];
            j++;
            hori++;
        }
    }
    while(i<n)
    {
         ans+=hori*a[i];
         i++;
    }
    while(j<m)
    {
        ans+=vert*b[j];
        j++;
    }
    cout<<ans;
    return 0;
}