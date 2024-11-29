//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &nums) {
        // Your Code Here
        double prefixProduct = 1;
        double suffixProduct = 1;

        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            
            if(prefixProduct==0) prefixProduct = 1;
            if(suffixProduct==0) suffixProduct = 1;

            prefixProduct *= (nums[i]);
            suffixProduct *= (nums[nums.size()-i-1]);

            double temp = prefixProduct;
            if(prefixProduct < suffixProduct) temp = suffixProduct;
            if(ans < temp) ans = temp;

        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends