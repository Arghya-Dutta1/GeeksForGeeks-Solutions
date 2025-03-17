//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    
    bool solve(int ind, vector<int>& arr, int sum){
        if(sum==0) return true;
        if(ind==0) return sum==arr[ind];
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool nt=solve(ind-1, arr, sum);
        bool t=false;
        if(arr[ind]<=sum)
            t=solve(ind-1, arr, sum-arr[ind]);
        return dp[ind][sum]=t||nt;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        dp.resize(arr.size(), vector<int>(sum+1, -1));
        return solve(arr.size()-1, arr, sum);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends