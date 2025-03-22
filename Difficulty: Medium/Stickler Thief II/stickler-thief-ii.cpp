//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& nums) {
        // your code here
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];

    auto rob = [&](int l, int r) {
      int prev1 = 0;  // dp[i - 1]
      int prev2 = 0;  // dp[i - 2]

      for (int i = l; i <= r; ++i) {
        const int dp = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = dp;
      }

      return prev1;
    };

    return max(rob(0, nums.size() - 2), rob(1, nums.size() - 1));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends