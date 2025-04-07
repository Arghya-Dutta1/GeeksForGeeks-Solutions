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
    
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            // adj[i[1]].push_back(i[0]);
        }
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
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends