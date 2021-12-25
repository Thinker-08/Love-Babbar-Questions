// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position
    bool exists(int x,int y,int n)
    {
        if(x<=0 || y<=0 || x>n || y>n)
            return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    const int MOD=1e3+10;
        vector<vector<int>> level(MOD,vector<int>(MOD,INT_MAX));
        vector<vector<bool>> vis(MOD,vector<bool>(MOD,false));
	    pair<int,int> initial=make_pair(KnightPos[0],KnightPos[1]);
	    pair<int,int> target=make_pair(TargetPos[0],TargetPos[1]);
	    queue<pair<int,int>> q;
	    q.push(initial);
	    vis[initial.first][initial.second]=true;
	    level[initial.first][initial.second]=0;
	    while(!q.empty())
	    {
	        pair<int,int> temp=q.front();
	        q.pop();
	        if(exists(temp.first+2,temp.second+1,N) and vis[temp.first+2][temp.second+1]!=true)
	        {
	            q.push(make_pair(temp.first+2,temp.second+1));
	            vis[temp.first+2][temp.second+1]=true;
	            level[temp.first+2][temp.second+1]=level[temp.first][temp.second]+1;
	            if(temp.first+2==target.first and temp.second+1==target.second)
	                break;
	        }
	        if(exists(temp.first+2,temp.second-1,N) and vis[temp.first+2][temp.second-1]!=true)
	        {
	            q.push(make_pair(temp.first+2,temp.second-1));
	            vis[temp.first+2][temp.second-1]=true;
	            level[temp.first+2][temp.second-1]=level[temp.first][temp.second]+1;
	            if(temp.first+2==target.first and temp.second-1==target.second)
	                break;
	        }
	        if(exists(temp.first-2,temp.second+1,N) and vis[temp.first-2][temp.second+1]!=true)
	        {
	            q.push(make_pair(temp.first-2,temp.second+1));
	            vis[temp.first-2][temp.second+1]=true;
	            level[temp.first-2][temp.second+1]=level[temp.first][temp.second]+1;
	            if(temp.first-2==target.first and temp.second+1==target.second)
	                break;
	        }
	        if(exists(temp.first-2,temp.second-1,N) and vis[temp.first-2][temp.second-1]!=true)
	        {
	            q.push(make_pair(temp.first-2,temp.second-1));
	            vis[temp.first-2][temp.second-1]=true;
	            level[temp.first-2][temp.second-1]=level[temp.first][temp.second]+1;
	            if(temp.first-2==target.first and temp.second-1==target.second)
	                break;
	            
	        }
	        if(exists(temp.first+1,temp.second+2,N) and vis[temp.first+1][temp.second+2]!=true)
	        {
	            q.push(make_pair(temp.first+1,temp.second+2));
	            vis[temp.first+1][temp.second+2]=true;
	            level[temp.first+1][temp.second+2]=level[temp.first][temp.second]+1;
	            if(temp.first+1==target.first and temp.second+2==target.second)
	                break;
	        }
	        if(exists(temp.first+1,temp.second-2,N) and vis[temp.first+1][temp.second-2]!=true)
	        {
	            q.push(make_pair(temp.first+1,temp.second-2));
	            vis[temp.first+1][temp.second-2]=true;
	            level[temp.first+1][temp.second-2]=level[temp.first][temp.second]+1;
	            if(temp.first+1==target.first and temp.second-2==target.second)
	                break;
	        }
	        if(exists(temp.first-1,temp.second+2,N) and vis[temp.first-1][temp.second+2]!=true)
	        {
	            q.push(make_pair(temp.first-1,temp.second+2));
	            vis[temp.first-1][temp.second+2]=true;
	            level[temp.first-1][temp.second+2]=level[temp.first][temp.second]+1;
	            if(temp.first-1==target.first and temp.second+2==target.second)
	                break;
	        }
	        
	        if(exists(temp.first-1,temp.second-2,N) and vis[temp.first-1][temp.second-2]!=true)
	        {
	            q.push(make_pair(temp.first-1,temp.second-2));
	            vis[temp.first-1][temp.second-2]=true;
	            level[temp.first-1][temp.second-2]=level[temp.first][temp.second]+1;
	            if(temp.first-1==target.first and temp.second-2==target.second)
	                break;
	        }
	    }
	    return level[target.first][target.second]!=INT_MAX? level[target.first][target.second]:-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends