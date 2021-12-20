// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        int ans=0,count=0;
        vector<int> v,t;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                v.push_back(i);
                count++;
            }
            else
                t.push_back(i);
        }
        if(count!=0)
        {
            int i=0,j=0,l,r,temp=0,maxi=0;
            while(i<n and j<n)
            {
                if(arr[j]<=k)
                    temp++;
                if(j-i+1<count)
                {
                    j++;
                }
                else
                {
                    if(temp>maxi)
                    {
                        l=i;
                        r=j;
                        maxi=temp;
                    }
                    if(arr[i]<=k)
                        temp--;
                    i++;
                    j++;
                }
            }
            int x=0;
            for(int z=l;z<=r;z++)
            {
                if(arr[z]>k)
                {
                    swap(arr[x],arr[z]);
                    x++;
                    ans++;
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends