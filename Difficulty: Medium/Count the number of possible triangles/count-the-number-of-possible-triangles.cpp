//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& nums) {
        // code here
        if (nums.size() < 3) return 0;

    int ans = 0;

    sort(nums.begin(), nums.end());

    for (int k = nums.size() - 1; k > 1; --k) {
      int i = 0;
      int j = k - 1;
      while (i < j)
        if (nums[i] + nums[j] > nums[k]) {
          ans += j - i;
          --j;
        } else ++i;
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends