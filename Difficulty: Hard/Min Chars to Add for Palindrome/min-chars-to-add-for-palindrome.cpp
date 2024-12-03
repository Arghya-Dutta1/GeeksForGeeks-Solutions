//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + '#' + rev;
        int n = combined.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) 
                len = lps[len - 1];
            if (combined[i] == combined[len]) 
                len++;
            lps[i] = len;
        }
        return s.size() - lps.back();
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends