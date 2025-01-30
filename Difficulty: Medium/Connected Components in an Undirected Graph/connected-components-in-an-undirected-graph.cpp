//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<bool> vis;
    
    void dfs(vector<vector<int>>& adj, vector<int>& path, int u){
        vis[u]=true;
        path.push_back(u);
        for(auto v:adj[u])
            if(!vis[v]) 
                dfs(adj, path, v);
    }
    
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code here
        vis.resize(v, false);
        vector<vector<int>> adj(v);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<v;i++){
            vector<int> p;
            if(!vis[i])
                dfs(adj, p, i);
            sort(p.begin(), p.end());
            if(p.size()>0)
                ans.push_back(p);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends