#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int cost = 0;
        int n,k,x;
        cin>>n>>k>>x;
        multiset<int> v;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            v.insert(temp);
        }
        auto it = v.begin();
        while(*it<k)
        {
            cost = cost + *it;
            v.erase(it);
            it = v.begin();
        }
        while(v.size()!=k && v.size()>2*k)
        {
            cost = cost + *it;
            v.erase(v.begin());
            it = v.begin();
        }
        cost = cost + (v.size()/2)*k;
        cout<<cost;
    }
}
