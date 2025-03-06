//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &text1, string &text2) {
        // code here
        int m=text1.size(), n=text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[m][n]=0;
        for(int i=m-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                if(text1[i]!=text2[j])
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
                else
                    dp[i][j]=1+dp[i+1][j+1];
            }
        return dp[0][0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends