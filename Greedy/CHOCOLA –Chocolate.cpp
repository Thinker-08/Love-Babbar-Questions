#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
void tests()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n-1),b(m-1);
    rep(i,0,n-1)
        cin>>a[i];
    rep(i,0,m-1)
        cin>>b[i];
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int hori=1,vert=1;
    int i=0,j=0,ans=0;
    while(i<n-1 and j<m-1)
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
    while(i<n-1)
    {
         ans+=hori*a[i];
         i++;
    }
    while(j<m-1)
    {
        ans+=vert*b[j];
        j++;
    }
    cout<<ans;
    newline;
}
int32_t main()
{
    fast;
    int q;
    cin>>q;
    while(q--)
    {
        tests();
    }
    return 0;
}