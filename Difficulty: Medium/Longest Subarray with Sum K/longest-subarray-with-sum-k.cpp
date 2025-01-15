//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> sumMap;
        int currSum = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];

            if (currSum == k)
                maxLen = i + 1;

            if (sumMap.find(currSum - k) != sumMap.end())
                maxLen = max(maxLen, i - sumMap[currSum - k]);

            if (sumMap.find(currSum) == sumMap.end())
                sumMap[currSum] = i;
        }

        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends