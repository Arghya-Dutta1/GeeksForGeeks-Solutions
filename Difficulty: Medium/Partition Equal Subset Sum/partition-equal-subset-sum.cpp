//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool knapsack(const vector<int>& nums, int subsetSum) {
    vector<bool> dp(subsetSum + 1);
    dp[0] = true;

    for (const int num : nums)
      for (int i = subsetSum; i >= num; --i)
        dp[i] = dp[i] || dp[i - num];

    return dp[subsetSum];
  }
  
    bool equalPartition(vector<int>& nums) {
        // code here
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        return knapsack(nums, sum / 2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends