//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int col, int n, vector<bool>& rows, vector<bool>& diag1, vector<bool>& diag2,
               vector<int>& curr, vector<vector<int>>& res) {
        if (col == n) {
            res.push_back(curr);
            return;
        }
        for (int row = 0; row < n; ++row) {
            int d1 = row + col;     
            int d2 = n - 1 + row - col; 
            if (!rows[row] && !diag1[d1] && !diag2[d2]) {
                // Place the queen
                rows[row] = diag1[d1] = diag2[d2] = true;
                curr[col] = row + 1; 
                solve(col + 1, n, rows, diag1, diag2, curr, res);
                rows[row] = diag1[d1] = diag2[d2] = false;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res; 
        vector<bool> rows(n, false); 
        vector<bool> diag1(2 * n - 1, false); 
        vector<bool> diag2(2 * n - 1, false); 
        vector<int> curr(n);       
        solve(0, n, rows, diag1, diag2, curr, res);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends