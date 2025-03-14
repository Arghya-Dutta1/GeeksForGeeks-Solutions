//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int coin(vector<int>& c, vector<vector<int>>& dp, int amt, int sm, int j){
        if(j==c.size()){    
            if(amt==sm) return 1;
            return 0;
        }
        if(dp[sm][j]!=-1) return dp[sm][j];
        int a=coin(c, dp, amt, sm, j+1);
        int b=0;
        if(sm+c[j]<=amt)
            b=coin(c, dp, amt, sm+c[j], j);
        return dp[sm][j]=a+b;            
    }
    
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<vector<int>> dp(sum+1, vector<int>(coins.size(), -1));
        return coin(coins, dp, sum, 0, 0);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends