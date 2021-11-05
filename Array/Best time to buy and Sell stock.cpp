include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
// { Driver Code Starts
int maxProfit(vector<int>& prices) {
        int mini=prices[0],profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(profit<(prices[i]-min(mini,prices[i])))
            {
                profit=(prices[i]-min(mini,prices[i]));
            }
            else
            {
                mini=min(mini,prices[i]);
            }
        }
        return profit;
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int x=maxProfit(v);
    cout<<x;
    return 0;
}