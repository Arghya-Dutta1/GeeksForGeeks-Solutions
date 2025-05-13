//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
    int dp[n+1][r+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=r;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            if(j>i)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%1000000007;
        }
    }
    return dp[n][r];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends