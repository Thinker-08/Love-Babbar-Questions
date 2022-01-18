#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int calc(int n)
{
    if(n==1)
        return 1;
    int res = calc(n/2);
    if(!(n&1))
        return (res)<<2;
    else
        return (res<<2)+((n/2)<<2)+1;
}
int32_t main()
{
    fast;
    int n;
    cin>>n;
    cout<<calc(n);
    return 0;
}