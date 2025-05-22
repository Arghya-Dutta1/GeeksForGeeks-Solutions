class Solution {
  public:
    int minDeletions(string S) {
        // code here
        int n=S.length();
        string t=S;
        reverse(t.begin(),t.end());
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int i=1;i<n+1;i++)
        {
            
            for(int j=1;j<n+1;j++)
            {
                
                if(S[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                
                
            }
        }
        
      return n-dp[n][n]; 
    }
};