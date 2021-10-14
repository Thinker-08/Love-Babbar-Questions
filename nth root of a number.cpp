#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
vs ans;
int main()
{
    bb;bb1;
    double n,i,mid;
    cin>>n>>i;
    double lo = 0,hi = n;
    while(hi-lo>1e-6)
    {
        mid = (hi+lo)/2;
        if(pow(mid,i)<n)
            lo = mid;
        else
            hi = mid;
    }
    cout<<lo<<endl;
    return 0;
}