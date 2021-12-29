// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isvalid(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    vector<pair<int,int>> movements{
        {1,0},{0,1},{-1,0},{0,-1}
    };
	vector<vector<int>>nearest(vector<vector<int>> &grid)
	{
	    vector<vector<int>> level(grid.size(),vector<int> (grid[0].size(),0));
	    vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
	    queue<pair<int,int>> q;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[i].size();j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push(make_pair(i,j));
	                level[i][j]=0;
	                vis[i][j]=1;
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        pair<int,int> temp=q.front();
	        q.pop();
	        for(auto move:movements)
	        {
	            if(!isvalid(temp.first+move.first,temp.second+move.second,grid))
	                continue;
	            if(vis[temp.first+move.first][temp.second+move.second]==1)
	                continue;
	            level[temp.first+move.first][temp.second+move.second]=level[temp.first][temp.second]+1;
	            q.push(make_pair(temp.first+move.first,temp.second+move.second));
	            vis[temp.first+move.first][temp.second+move.second]=1;
	        }
	    }
	    return level;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends