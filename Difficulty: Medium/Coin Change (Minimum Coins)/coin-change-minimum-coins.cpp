//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dp;
    int findMinCoins(vector<int>& coins, int amt){
        if(amt==0) return 0;
        if(amt<0) return INT_MAX;

        if(dp[amt]!=-1) return dp[amt];

        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int pos=findMinCoins(coins, amt-coins[i]);
            if(pos==INT_MAX) continue;
            ans=min(ans, pos+1);
        }

        return dp[amt]=ans;
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        dp.resize(sum+1, -1);
        int ans=findMinCoins(coins, sum);
        return ans!=INT_MAX?ans:-1;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends