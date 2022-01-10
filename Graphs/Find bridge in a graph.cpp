// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	static const int N=1e5+10;
	int C,D;
	void dfs(vector<int> adj[],vector<int> &vis,int parent)
	{
	    vis[parent]=1;
	    for(auto child:adj[parent])
	    {
	        if(!vis[child])
	            dfs(adj,vis,child);
	    }
	}
	void dfs2(vector<int> adj[],vector<int> &vis,int parent)
	{
	    vis[parent]=1;
	    for(auto child:adj[parent])
	    {
	        if((child==C and parent==D) ||(child==D and parent==C))
	            continue;
	        if(!vis[child])
	            dfs2(adj,vis,child);
	    }
	}
	bool check(vector<int> adj[],int V,int c,int d)
	{
	    int count1=0,count2=0;
	    vector<int> vis(N,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            count1++;
	            dfs(adj,vis,i);
	        }
	    }
	    for(int i=0;i<V;i++)
	        vis[i]=0;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            count2++;
	            dfs2(adj,vis,i);
	        }
	    }
	    if(count1==count2)
	        return false;
	    else
	        return true;
	}
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        C=c;
        D=d;
        if(check(adj,V,c,d))
            return 1;
        else
            return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends