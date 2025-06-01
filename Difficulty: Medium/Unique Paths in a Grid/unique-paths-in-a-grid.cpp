class Solution {
  public:
    vector<vector<int>> dp;
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m=grid.size(), n=grid[0].size();
        dp.resize(m+1, vector<int>(n+1, 0));
        dp[0][1]=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(!grid[i-1][j-1])
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};