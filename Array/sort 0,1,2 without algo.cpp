#include<bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
int main()
{
    bb;bb1;
    int n,k,z,o,t;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]==0)
            z++;
        if(arr[i]==1)
            o++;
        if(arr[i]==2)
            t++;
    }
    rep(i,0,n)
    {
        if(z!=0)
        {
            arr[i]=0;
            z--;
        }
        else
        {
            if(o!=0)
            {
                arr[i]=1;
                o--;
            }
            else
            {
                if(t!=0)
                {
                    arr[i]=2;
                    t--;
                }
            }
        }
    }   
    rep(i,0,n)
        cout<<arr[i]<<" ";
    return 0;
}