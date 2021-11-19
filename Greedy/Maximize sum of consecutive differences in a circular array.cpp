// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    int i=0,j=n-1,k=0;
    vector<int> v;
    sort(arr,arr+n);
    while(i!=j)
    {
        if(k%2==0)
        {
            v.push_back(arr[i]);
            i++;
        }
        else
        {
            v.push_back(arr[j]);
            j--;
        }
        k++;
    }
    v.push_back(arr[i]);
    int ans=0;
    for(int l=0;l<v.size()-1;l++)
    {
        ans=ans+abs(v[l]-v[l+1]);
    }
    ans=ans+abs(v[n-1]-v[0]);
    return ans;
}