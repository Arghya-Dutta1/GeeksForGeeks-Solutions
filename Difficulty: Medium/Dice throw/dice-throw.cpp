class Solution {
  public:
    int noOfWays(int k, int n, int x) {
        // code here
        int mod = 1e9 + 7;
        vector<vector<int>> f(n+1, vector<int>(x+1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= min(x, i * k); ++j)
                for (int h = 1; h <= min(j, k); ++h)
                    f[i][j] = (f[i][j] + f[i - 1][j - h]) % mod;
        return f[n][x];
    }
};