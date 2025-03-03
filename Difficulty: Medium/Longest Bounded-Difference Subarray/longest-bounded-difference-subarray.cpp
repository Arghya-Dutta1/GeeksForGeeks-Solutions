//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
    deque<int> maxDeque, minDeque;  
    int start = 0, maxLen = 0, bestStart = 0;

    for (int end = 0; end < n; end++) {
        while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[end]) 
            maxDeque.pop_back();
        maxDeque.push_back(end);

        while (!minDeque.empty() && arr[minDeque.back()] >= arr[end]) 
            minDeque.pop_back();
        minDeque.push_back(end);

        while (arr[maxDeque.front()] - arr[minDeque.front()] > x) {
            start++;
            if (maxDeque.front() < start) maxDeque.pop_front();
            if (minDeque.front() < start) minDeque.pop_front();
        }

        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            bestStart = start;
        }
    }

    return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends