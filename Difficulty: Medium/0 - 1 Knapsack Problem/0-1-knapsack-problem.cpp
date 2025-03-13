//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    
    int solve(int ind, int W, vector<int> &val, vector<int> &wt){
        if(ind<0||W==0) return 0;
        if(dp[ind][W]!=-1) return dp[ind][W];
        int nt=solve(ind-1, W, val, wt);
        int t=(wt[ind]<=W? val[ind]+solve(ind-1, W-wt[ind], val, wt) : 0);
        return dp[ind][W]=max(t, nt);
    }
  
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        dp.resize(val.size(), vector<int>(W+1, -1));
        return solve(val.size()-1, W, val, wt);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends