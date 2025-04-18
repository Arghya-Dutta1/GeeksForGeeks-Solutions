//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string s1=s;
        reverse(s1.begin(), s1.end());
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        dp[n][n]=0;
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                if(s[i]==s1[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
            }
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends