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
    int minlen=INT_MAX,sum=0,i=0,j=0;
    while(i<nums.size() and j<nums.size())
    {
        sum=sum+nums[j];
        if(sum<target)
        {
            j++;
        }
        else
        {
            minlen=min(minlen,j-i+1);
            while(sum>=target)
            {
                minlen=min(minlen,j-i+1);
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
    }
    return minlen!=INT_MAX?minlen:0;
}
int main()
{
    int n,target;
    cin>>n>>target;
    int arr[n];
    rep(i,0,n)
        cin>>arr[i];
    int ans=minSubArrayLen(target,arr);
    cout<<ans;
}