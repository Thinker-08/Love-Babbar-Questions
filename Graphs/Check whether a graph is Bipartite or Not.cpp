// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool ans=true;
    void check(vector<int> adj[],vector<int> &vis, vector<int> &color,int parent,int col)
    {
        if(color[parent]!=-1 and color[parent]!=col)
        {
            ans=false;
            return;
        }
        if(vis[parent])
            return ;
        vis[parent]=1;
        color[parent]=col;
        for(auto child:adj[parent])
        {
            check(adj,vis,color,child,(col^1));
        }
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            check(adj,vis,color,i,1);   
	    }
	    if(ans)
	        return true;
	    else
	        return false;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends