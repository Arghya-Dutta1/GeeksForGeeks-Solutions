class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &matrix) {
        // code here
        vector<int> r,c;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
        for(auto i:r)
            for(int j=0;j<matrix[0].size();j++)
                matrix[i][j]=0;
        for(auto i:c)
            for(int j=0;j<matrix.size();j++)
                matrix[j][i]=0;
    }
};