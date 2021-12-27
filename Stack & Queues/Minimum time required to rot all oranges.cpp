// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    vector<pair<int,int>> movements{
        {1,0},{-1,0},{0,1},{0,-1}
    };
    bool isvalid(vector<vector<int>> &grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        const int N=1e3;
        vector<vector<int>> vis(N,vector<int> (N,0)),level(N,vector<int>(N));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    level[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            for(auto move : movements)
            {
                if(!isvalid(grid,temp.first+move.first,temp.second+move.second))
                    continue;
                if(vis[temp.first+move.first][temp.second+move.second])
                    continue;
                if(grid[temp.first+move.first][temp.second+move.second]==0)
                    continue;
                q.push({temp.first+move.first,temp.second+move.second});
                level[temp.first+move.first][temp.second+move.second]=level[temp.first][temp.second]+1;
                vis[temp.first+move.first][temp.second+move.second]=1;
                ans=max(ans,level[temp.first+move.first][temp.second+move.second]);
            }
        }
        int flag=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            return -1;
        return ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends