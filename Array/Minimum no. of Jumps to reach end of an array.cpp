#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
void fun(vector<ll> &v,ll i,ll s,ll *x)
{
    if(s<0)
        return;
    if(s==0)
    {
        *x=*x+1; 
        return;
    }
    if(i==v.size())
        return;
    //liya
    fun(v,i+1,s-v[i],x);
    // nahi liya
    fun(v,i+1,s,x);
}
int main()
{
    bb;bb1;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    if(v.size()<=1)
        cout<<-1;
    else
    {
        if(v[0]==0)
            cout<<-1;
        else
        {
            int maxReach=v[0];
            int step=v[0];
            int jump=1;
            int i=1;
            for(i=1;i<n;i++)
            {
                if(i==n-1)
                    cout<<jump;
                maxReach=max(maxReach,v[i]+i);
                step--;
                if(step==0)
                {
                    jump++;
                    if(i>=maxReach)
                    {
                        cout<<-1;
                        break;
                    }
                    cout<<maxReach<<" "<<i<<endl;
                    step=maxReach-i;
                }
            }
        }
    }
    return 0;
}