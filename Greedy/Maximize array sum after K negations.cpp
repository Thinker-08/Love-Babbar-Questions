// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        long long sum=0;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0 && k>0)
            {
                a[i]=-a[i];
                k--;
            }
        }
        sort(a,a+n);
        i=0;
        while(i<n)
        {
            if(k>0)
            {
                a[i]=-a[i];
                k--;  
            }
            else
                break;
        }
        return accumulate(a,a+n,0);
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends