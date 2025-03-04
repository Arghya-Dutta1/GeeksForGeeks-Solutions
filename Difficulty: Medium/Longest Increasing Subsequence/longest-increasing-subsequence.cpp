//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > lis.back()) lis.push_back(nums[i]);
            else {
                int j = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[j] = nums[i];
            }
        }
        return lis.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends