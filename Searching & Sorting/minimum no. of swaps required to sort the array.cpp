// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.first<b.first;
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    int c=0;
	    vector<pair<int,int>> vec(n);
	    for(int i=0;i<n;i++){
	        vec[i]={nums[i],i};
	    }
	    sort(vec.begin(),vec.end());
	    
	    for(int i=0;i<n;i++){
	        if(vec[i].second==i) continue;
	        else{
	            swap(vec[i],vec[vec[i].second]);
	            c++;
	            i--;
	        }
	    }
	    return c;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends