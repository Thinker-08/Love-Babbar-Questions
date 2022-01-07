#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
const int N=1e3+10;
vector<vector<int>> dp(N,vector<int>(N));
int solve(int h,int a,int i)
{
    if(a<=0 || h<=0)
        return 0;
    if(dp[h][a]!=-1)
        return dp[h][a];
    int x=0,y=0,z=0;
    if(i!=1) x=1+solve(h+3,a+2,1);
    if(i!=2) y=1+solve(h-5,a-10,2);
    if(i!=3) z=1+solve(h-20,a+5,3);
    return dp[h][a]=max(x,max(y,z));
}
void reset()
{
    rep(i,0,N)
    {
        rep(j,0,N)
        {
            dp[i][j]=-1;
        }
    }
}
void tests()
{
    reset();
    int h,a;
    cin>>h>>a;
    cout<<max(solve(h+3,a+2,1),max(solve(h-5,a-10,2),solve(h-20,a+5,3)));
    newline;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        tests();
    }
    return 0;
}