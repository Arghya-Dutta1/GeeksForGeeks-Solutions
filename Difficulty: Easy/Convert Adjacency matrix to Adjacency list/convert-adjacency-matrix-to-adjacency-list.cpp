class Solution {
  public:
    vector<vector<int>> matToAdj(vector<vector<int>>& mat) {
        // code here
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]==1)
                    ans[i].push_back(j);
        return ans;
    }
};