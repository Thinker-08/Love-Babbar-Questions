#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> s;
        vector<long long> left(n),right(n);
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                left[i]=0;
                s.push(i);
            }
            else
            {
                while(!s.empty() and arr[s.top()]>=arr[i])
                    s.pop();
                left[i]=s.empty()?0:s.top()+1;
                s.push(i);
            }
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                right[i]=n-1;
                s.push(i);
            }
            else
            {
                while(!s.empty() and arr[s.top()]>=arr[i])
                    s.pop();
                right[i]=s.empty()?n-1:s.top()-1;
                s.push(i);
            }
        }
        long long maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]*(right[i]-left[i]+1));
        }
        return maxi;
    }
};


int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
    return 0;
}
  // } Driver Code Ends