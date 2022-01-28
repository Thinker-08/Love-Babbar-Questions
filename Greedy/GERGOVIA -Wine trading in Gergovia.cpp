#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int32_t main()
{
    fast;
    int n;
    cin>>n;
    while(n)
    {
        vector<int> v(n);
        rep(i,0,n)
            cin>>v[i];
        int ans=0;
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                if(v[i]==0)
                    continue;
                s.push({v[i],i});
            }
            else
            {
                if(v[i]==0)
                    continue;
                s.push({v[i],i});
                while(1)
                {
                    if(s.size()>1)
                    {
                        pair<int,int> one = s.top();
                        s.pop();
                        pair<int,int> two = s.top();
                        s.pop();
                        if((one.first>0 and two.first<0)
                            or (one.first<0 and two.first>0))
                        {
                            ans+=abs(one.second-two.second)*min(abs(one.first),abs(two.first));
                            if(one.first+two.first==0)
                            {
                                continue;
                            }
                            else
                            {
                                if(abs(one.first)>abs(two.first))
                                {
                                    s.push({one.first+two.first,one.second});
                                }
                                else
                                {
                                    s.push({one.first+two.first,two.second});
                                }
                            }
                        }  
                        else
                        {
                            s.push(two);
                            s.push(one);
                            break;
                        }
                    }
                    else
                        break;
                }
            }
        }
        cout<<ans;
        newline;
        cin>>n;
    }
    return 0;
}
        
        