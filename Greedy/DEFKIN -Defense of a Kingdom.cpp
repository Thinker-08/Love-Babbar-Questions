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
    int w,h,n;
    cin>>w>>h>>n;
    if(n==0)
        cout<<w*h;
    else
    {
        vector<int> a(n),b(n);
        a.push_back(0);a.push_back(w+1);
        b.push_back(0);b.push_back(h+1);
        rep(i,0,n)
            cin>>a[i]>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int maxi_1=0,maxi_2=0;
        for(int i=1;i<n+2;i++)
        {
            maxi_1=max(maxi_1,a[i]-a[i-1]-1);
            maxi_2=max(maxi_2,b[i]-b[i-1]-1);
        }
        cout<<maxi_1*maxi_2;
    }
    newline;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
    return 0;
}
        
        