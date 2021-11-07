// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
         multiset<long long> s;
        sort(a.begin(),a.end());
        for(int i=0;i<m;i++)
        {
            s.insert(a[i]);
        }
        long long min=INT_MAX;
        auto it1=s.begin();
        for(auto it=s.begin();it!=s.end();it++)
        {
            it1=it;
        }
        min=abs((*s.begin())-(*(--s.end())));
        for(int i=m;i<n;i++)
        {
            auto x=s.begin();
            if(a[i]-(*(++x))<min)
            {
                min=a[i]-(*(x));
            }
            s.erase(s.begin());
                s.insert(a[i]);
        }
        return min;
    
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends