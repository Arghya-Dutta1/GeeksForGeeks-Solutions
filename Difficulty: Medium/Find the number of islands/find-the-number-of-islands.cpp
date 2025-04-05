//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<char>>& g, vector<vector<int>>& v, int i, int j){
        int n=g.size(), m=g[0].size();
	    if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] || g[i][j] == 'W') return;
        v[i][j] = 1;
        dfs(g, v, i+1, j);
        dfs(g, v, i, j+1);
        dfs(g, v, i-1, j);
        dfs(g, v, i, j-1);
        dfs(g, v, i+1, j+1);
        dfs(g, v, i-1, j+1);
        dfs(g, v, i-1, j-1);
        dfs(g, v, i+1, j-1);
    }
    
    // Function to find the number of islands.
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] && grid[i][j]=='L'){
                    dfs(grid, vis, i, j);
                    ans++;
                }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends