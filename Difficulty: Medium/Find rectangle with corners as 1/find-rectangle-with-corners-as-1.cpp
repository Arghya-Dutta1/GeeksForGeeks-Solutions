class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (mat[i][j] == 1 && mat[i][k] == 1) {
                        for (int l = i + 1; l < m; l++) {
                            if (mat[l][j] == 1 && mat[l][k] == 1)
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
