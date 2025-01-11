//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> lastIndex;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.size(); end++) {
            char currentChar = s[end];
            if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1;
            }
            lastIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends