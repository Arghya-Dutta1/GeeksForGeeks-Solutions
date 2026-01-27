class Solution {
  public:
    bool flag;
    void check(vector<vector<char>>& b, vector<vector<bool>>& ck, string& w, int i, int j, int m){
        if(m==w.size()){
            flag=true;
            return;
        }
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || ck[i][j])
            return;

        if(b[i][j]==w[m]){
            ck[i][j]=true;
            check(b, ck, w, i+1, j, m+1);
            check(b, ck, w, i, j+1, m+1);
            check(b, ck, w, i-1, j, m+1);
            check(b, ck, w, i, j-1, m+1);
            ck[i][j]=false;
        }
        return;
    }
  
    bool isWordExist(vector<vector<char>>& board, string& word) {
        // Code here
        vector<vector<bool>> ck(board.size(), vector<bool>(board[0].size(), false));
        flag=false;
        int i,j;
        for(i=0;i<board.size();i++)
            for(j=0;j<board[0].size();j++){
                check(board, ck, word, i, j, 0);
            }
        return flag;
    }
};
