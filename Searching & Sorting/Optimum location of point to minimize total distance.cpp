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
double distance(pair<int,int> a,pair<int,int> b)
{
    return sqrt((b.first-a.first)*(b.first-a.first) + 
    (b.second-a.second)*(b.second-a.second));
}
float check(int m,int c,vector<pair<int,int>> &v,float test_x)
{
    float test_y=m*test_x+c;
    double ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans+=distance(v[i],{test_x,test_y});
    }
    return ans;
}
int32_t main()
{
    fast;
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    rep(i,0,n)
        cin>>v[i].first>>v[i].second;  
    int m,c;
    cin>>m>>c;
    float lo=-1*(1e17),hi=1e17;
    while(hi>lo)
    {

        float mid = (lo+hi)/2;
        float a = check(m,c,v,mid);
        float b = check(m,c,v,mid+1);
        if(b<a)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid;
        }
    } 
    cout<<check(m,c,v,lo);
    newline;
    return 0;
}