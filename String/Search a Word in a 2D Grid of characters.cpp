// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checks1(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks1(grid,word.substr(1),i,j+1);
            }
        }
        else
            return false;
    }
    bool checks2(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks2(grid,word.substr(1),i,j-1);
            }
        }
        else
            return false;
    }
    bool checks3(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks3(grid,word.substr(1),i+1,j);
            }
        }
        else
            return false;
    }
    bool checks4(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks4(grid,word.substr(1),i-1,j);
            }
        }
        else
            return false;
    }
    bool checks5(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks5(grid,word.substr(1),i+1,j+1);
            }
        }
        else
            return false;
    }
    bool checks6(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks6(grid,word.substr(1),i+1,j-1);
            }
        }
        else
            return false;
    }
    bool checks7(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks7(grid,word.substr(1),i-1,j+1);
            }
        }
        else
            return false;
    }
    bool checks8(vector<vector<char>>& grid,string word,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==word[0])
        {
            if(word.length()==1)
                return true;
            else
            {
                return checks8(grid,word.substr(1),i-1,j-1);
            }
        }
        else
            return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	    vector<vector<int>> ans;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==word[0])
                {
                   if(checks1(grid,word,i,j))
                   {
                       ans.push_back({i,j});
                   }
                   else if(checks2(grid,word,i,j))
                        ans.push_back({i,j});
                    else if(checks3(grid,word,i,j))
                        ans.push_back({i,j});
                    else if(checks4(grid,word,i,j))
                        ans.push_back({i,j});
                    else if(checks5(grid,word,i,j))
                        ans.push_back({i,j});
                    else if(checks6(grid,word,i,j))
                        ans.push_back({i,j});
                    else if(checks7(grid,word,i,j))
                        ans.push_back({i,j});
                    else if(checks8(grid,word,i,j))
                        ans.push_back({i,j});
                }
            }
        }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends