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
    int sum1=0,sum2=0,sum3=0;
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> a(n),b(m),c(o);
    rep(i,0,n)
    {cin>>a[i];sum1+=a[i];}
    rep(i,0,m)
    {cin>>b[i];sum2+=b[i];}
    rep(i,0,o)
    {cin>>c[i];sum3+=c[i];}
    int i=0,j=0,k=0;
    while(true)
    {
        if(i==n or j==m or k==o)
        {    cout<<0;break;}
        else
        {
            if(sum1==sum2 and sum2==sum3)
                {cout<<sum1;break;}
            else
            {
                if(sum1>=sum2 and sum1>=sum3)
                    sum1-=a[i++];
                else
                    if(sum2>=sum1 and sum2>=sum3)
                        sum2-=b[j++];
                    else
                        if(sum3>=sum2 and sum3>=sum1)
                            sum3-=c[k++];
            }   
        }
    }
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


