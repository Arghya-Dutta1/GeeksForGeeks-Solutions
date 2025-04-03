//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& g) {
        // Code here
        int n=g.size();
        int m=g[0].size();

        queue<pair<int, int>> q;
        vector<pair<int, int>> k={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> level(n+1, vector<int>(m+1, 0));
        int ans=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==2){
                    q.push({i,j});
                }
        
        while(q.size()>0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto it:k){
                int x=i+it.first;
                int y=j+it.second;
                
                if(x>=0 && x<n && y>=0 && y<m && g[x][y]==1){
                    q.push({x,y});
                    g[x][y]=2;
                    level[x][y]=level[i][j]+1;
                }
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(g[i][j]==1) return -1;
                ans=max(ans, level[i][j]);
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
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends