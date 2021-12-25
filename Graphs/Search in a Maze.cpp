// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void dfs(int i,int j,vector<vector<int>> &m,vector<vector<bool>> &vis,string temp)
    {
        if(i<0 || j<0)
            return;
        if(i>=m.size() || j>=m.size())
            return;
        if(vis[i][j] || m[i][j]==0)
            return;
        if(i==m.size()-1 and j==m.size()-1)
            ans.push_back(temp);
        vis[i][j]=true;
        dfs(i+1,j,m,vis,temp+'D');
        dfs(i-1,j,m,vis,temp+'U');
        dfs(i,j+1,m,vis,temp+'R');
        dfs(i,j-1,m,vis,temp+'L');
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        const int N=1e3;
        vector<vector<bool>> vis(N,vector<bool>(N,false));
        dfs(0,0,m,vis,"");
        if(ans.empty())
        {
            ans.push_back("-1");
            return ans;
        }
        else
        {
            sort(ans.begin(),ans.end());
            return ans;
        }
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends