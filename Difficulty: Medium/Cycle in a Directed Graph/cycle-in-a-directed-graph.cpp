//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    vector<bool> vis;
    vector<bool> p;
    
    bool dfs(vector<vector<int>>& adj, int u){
        if(!vis[u]){
            vis[u]=true;
            p[u]=true;
            for(auto v:adj[u]){
                if(!vis[v] && dfs(adj, v))
                    return true;
                else if(p[v])
                    return true;
            }
        }
        p[u]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>>& adj) {
        // code here
        vis.resize(V+1, false);
        p.resize(V+1, false);
        for(int i=0;i<V;i++)
            if(!vis[i] && dfs(adj, i))
                return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends