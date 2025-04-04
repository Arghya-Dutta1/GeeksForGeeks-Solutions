//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<bool> vis;
    
    bool dfs(vector<vector<int>>& adj, int vertex, int par){
        vis[vertex] = true;
        for(auto c : adj[vertex]){
            if(c == par) continue;
            if(vis[c]) return true;
            if(dfs(adj, c, vertex)) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> edges) {
        vis.assign(V, false);
        vector<vector<int>> adj(V);

        for(auto& i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i = 0; i < V; i++){
            if(!vis[i] && dfs(adj, i, -1)) return true;
        }

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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends