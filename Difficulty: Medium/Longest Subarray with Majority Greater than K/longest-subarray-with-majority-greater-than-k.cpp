//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = (arr[i] > k) ? 1 : -1;

        unordered_map<int, int> firstSeen;
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += mapped[i];

            if (prefixSum > 0) {
                maxLen = i + 1;
            } else {
                if (firstSeen.find(prefixSum - 1) != firstSeen.end()) {
                    maxLen = max(maxLen, i - firstSeen[prefixSum - 1]);
                }
            }

            if (firstSeen.find(prefixSum) == firstSeen.end()) {
                firstSeen[prefixSum] = i;
            }
        }

        return maxLen;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends