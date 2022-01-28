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
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int mini=INT_MAX,sum=0;
    int i=0,j=0;
    while(j<n)
    {
        sum=sum+v[j];
        mini=min(mini,sum);
        while(sum>mini and i<=j)
        {
            sum=sum-v[i];
            i++;
        }
        j++;
    }
    cout<<mini;
    return 0;
}
        
        