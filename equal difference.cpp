#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<ll,ll> mp;
        vector<ll> v;
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            v.push_back(temp);
            mp[temp] = mp[temp] + 1;
        }
        map<ll,ll> :: iterator test = mp.begin();
        for(map<ll,ll> :: iterator it = mp.begin();it!=mp.end();it++)
        {
            if((*it).second>(*test).second){
                test = it;
            }
            else
            {
                continue;
            }
        }
        if(mp.size()>2 || (*test).second>1)
        {
            if(n-(*test).second<(n-2))
            {
                cout<<n-(*test).second<<endl;
            }
            else
            {
                cout<<n-2<<endl;
            }
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
