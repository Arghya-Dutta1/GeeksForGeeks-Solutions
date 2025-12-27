class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int m=matrix.size(), n=matrix[0].size(), lo=matrix[0][0], hi=matrix[m-1][n-1]+1;
        while(lo<hi) {
            int mid=lo+(hi-lo)/2, count=0;
            for(int i=0; i<m; i++) {
                int j=n-1;
                while(j>=0 && matrix[i][j]>mid) j--;
                count+=(j+1);
            }
            if(count<k) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};