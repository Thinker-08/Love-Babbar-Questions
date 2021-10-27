#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int *findTwoElement(int *arr, int n) {
        map<int,int> mp;
        int a[2];
        int coun=1;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=mp[arr[i]]+1;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v.push_back((*it).first);
            if((*it).second==2)
            { 
                a[0] = (*it).first;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==coun)
                coun++;
            else
            {
                a[1] = coun;
                break;
            }
        }
        return a;
    }
int main()
{
    fast;
    int n;
    cin>>n;
    int v[n];
    rep(i,0,n)
    {
        cin>>v[i];
    }
    int *a = findTwoElement(v,n);
    cout<<*a<<" "<<*(a+sizeof(int));
}