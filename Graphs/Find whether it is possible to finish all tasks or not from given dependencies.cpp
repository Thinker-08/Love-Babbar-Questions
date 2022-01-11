// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool check(vector<vector<int>> &adj, vector<int> &vis,vector<int> &stack,int parent)
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
	bool isPossible(int N, vector<pair<int, int> >& pre)
	{
	    vector<vector<int>> adj(N);
	    vector<int> vis(N,0);
	    vector<int> stack(N,0);
	    bool ans=false;
	    for(int i=0;i<pre.size();i++)
	    {
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i] and check(adj,vis,stack,i))
	        {
	            ans=true;
	        }
	    }
	    return (!ans);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends