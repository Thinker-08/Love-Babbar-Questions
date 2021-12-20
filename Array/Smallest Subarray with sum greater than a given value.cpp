#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#define MOD 1e9+7
int minSubArrayLen(int target, vector<int>& nums) 
{
    int ans=nums.size()+1,i=0,j=0,sum=0;
    while(j<nums.size())
    {
        sum=sum+nums[j];
        if(sum<target)
            j++;
        else
        {
            while(sum>=target)
            {
                ans=min(ans,j-i+1);
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
    }
    if(ans==nums.size()+1)
        return 0;
    else
        return ans;
}
int main()
{
    fast;
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int ans=minSubArrayLen(target,v);
    cout<<ans;
    return 0;
}