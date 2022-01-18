// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:
    static const int N=1e3+10;
    bool flag=false;
    void dfs(vector<vector<pair<int,int>>> &adj,vector<int> &vis,int k,int temp,int parent)
    {
        if(temp>=k)
        {
            flag=true;
            return;
        }
        vis[parent]=1;
        for(auto child:adj[parent])
        {
            if(vis[child.first])
                continue;
            dfs(adj,vis,k,temp+child.second,child.first);
        }
        vis[parent]=0;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
        vector<vector<pair<int,int>>> adj(N,vector<pair<int,int>>(N));
        vector<int> vis(N,0);
        for(int i=0;i<E;i++)
        {
            adj[a[3*i]].push_back({a[3*i+1],a[3*i+2]});
            adj[a[3*i+1]].push_back({a[3*i],a[3*i+2]});
        }
        dfs(adj,vis,k,0,0);
        return flag;
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends