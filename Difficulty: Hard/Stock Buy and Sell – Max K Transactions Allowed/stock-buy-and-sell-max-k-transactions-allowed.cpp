//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(vector<int>& prices, int k,int i,bool canBuy,vector<vector<vector<int>>>&dp){
        if(i==prices.size() || k==0 ) return 0;
        if(dp[i][k][canBuy] != -1) return dp[i][k][canBuy];
        int involve =0, ignore=0;
        if(canBuy==true){
            involve=-prices[i] + solve(prices,k,i+1,false,dp);
            ignore=solve(prices,k,i+1,true,dp);
        }
        else{
            involve=prices[i] + solve(prices,k-1,i+1,true,dp);
            ignore=solve(prices,k,i+1,false,dp);
        }
        return dp[i][k][canBuy]= max(involve,ignore);
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(prices,k,0,true,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends