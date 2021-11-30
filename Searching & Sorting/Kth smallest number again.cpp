#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first<b.first;
}

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<pair<ll,ll>> v(n);
        rep(i,0,n)
            cin>>v[i].first>>v[i].second;
        sort(v.begin(),v.end(),cmp);
        vector<ll> tests(q);
        rep(i,0,q)
        {
            cin>>tests[i];
        }
        stack<pair<ll,ll>> s;
        s.push(v[0]);
        rep(i,1,n)
        {
            pair<ll,ll> to=s.top();
            if(s.top().second<v[i].first)
                s.push(v[i]);
            else
            {
                if(s.top().second<v[i].second)
                {
                    to.second=v[i].second;
                    s.pop();
                    s.push(to);
                }
            }
        }
        vector<pair<ll,ll>> combined;
        while(!s.empty())
        {
            combined.push_back(s.top());
            s.pop();
        }
        reverse(combined.begin(),combined.end());
        for(ll i=0;i<q;i++)
        {
            ll flag=0;
            ll sum=0;
            sum=combined[0].second-combined[0].first+1;
            for(ll j=0;j<combined.size();j++)
            {
                if(combined[0].first+tests[i]-1<=combined[0].second)
                {
                    cout<<combined[0].first+tests[i]-1<<endl;
                    flag=1;
                    break;
                }
                else
                {
                    if(j==0)
                        ;
                    else
                    {
                        if(combined[j].first+tests[i]-sum-1<=combined[j].second)
                        {
                            cout<<combined[j].first+tests[i]-sum-1<<endl;
                            flag=1;
                            break;
                        }
                        else
                        {
                            sum=sum+combined[j].second-combined[j].first+1;
                        }
                    }
                }     
            }
            if(flag==0)
                cout<<-1<<endl;
        }
    }
    return 0;
}