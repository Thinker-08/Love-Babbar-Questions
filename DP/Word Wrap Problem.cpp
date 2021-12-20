// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        vector<vector<int>> spaces(nums.size()+1,vector<int>(nums.size()+1,0)),
        cost(nums.size()+1,vector<int>(nums.size()+1,0));
        vector<int> min_val(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            spaces[i][i]=k-nums[i-1];
            for(int j=i+1;j<=nums.size();j++)
            {
                spaces[i][j]=spaces[i][j-1]-nums[j-1]-1;
            }
        }
        for(int i=1;i<nums.size()+1;i++)
        {
            for(int j=i;j<nums.size()+1;j++)
            {
                if(spaces[i][j]<0)
                    cost[i][j]=INT_MAX;
                else if(spaces[i][j]>=0 and j==nums.size())
                    cost[i][j]=0;
                else
                    cost[i][j]=spaces[i][j]*spaces[i][j];
            }
        }
        min_val[0]=0;
        for(int i=1;i<nums.size()+1;i++)
        {
            min_val[i]=INT_MAX;
            for(int j=1;j<=i;j++)
            {
                if(cost[j][i]!=INT_MAX and min_val[j-1]+cost[j][i]<min_val[i])
                    min_val[i]=min_val[j-1]+cost[j][i];
            }
        }
        return min_val[nums.size()];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends