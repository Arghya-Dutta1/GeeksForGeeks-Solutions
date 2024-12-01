//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &p) {
        // code here
        int n=p.size(), ans=0;
        vector<int> pm(n, 0);
        pm[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--) 
            pm[i]=max(p[i], pm[i+1]);
        for(int i=0;i<n;i++)
            ans=max(ans, pm[i]-p[i]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends