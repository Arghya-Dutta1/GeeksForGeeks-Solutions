//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> countBits(int n) {
        // code here
        vector<int> ans;
        for(int i=0; i<=n; i++)
            ans.push_back(__builtin_popcount(i));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> ans = sol.countBits(n);
        for (auto x : ans)
            cout << x << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends