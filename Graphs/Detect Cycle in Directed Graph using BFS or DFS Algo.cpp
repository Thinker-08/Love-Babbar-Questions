// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(vector<int> adj[], vector<int> &vis,vector<int> &stack,int parent)
    {
        stack[parent]=1;
        if(!vis[parent])
        {
            vis[parent]=1;
            for(auto child:adj[parent])
            {
                if(!vis[child] and check(adj,vis,stack,child))
                    return true;
                if(stack[child])
                    return true;
            }
        }
        stack[parent]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> stack(V,0);
        vector<int> vis(V,0);
        bool c=false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i] and check(adj,vis,stack,i))
            {
                c=true;
            }
        }
        return c;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends