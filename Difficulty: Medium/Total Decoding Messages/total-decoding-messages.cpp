//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &s) {
        // Code here
        int n = s.size();
        int prevTwo = 0, prevOne = 1;
      
        for (int i = 1; i <= n; ++i) {
            int current = s[i - 1] != '0' ? prevOne : 0;
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                current += prevTwo; 
            }
          
            prevTwo = prevOne; 
            prevOne = current; 
        }
        return prevOne;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends