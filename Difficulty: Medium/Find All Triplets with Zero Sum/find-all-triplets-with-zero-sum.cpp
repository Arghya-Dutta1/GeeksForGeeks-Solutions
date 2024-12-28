//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> findTriplets(vector<int> &a) {
        int n = a.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i)
            m[a[i]].push_back(i);

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = -1 * (a[i] + a[j]);
                if (m.find(x) != m.end()) {
                    for (auto k : m[x]) {
                        if (k > j)
                            res.push_back({i, j, k});
                    }
                }
            }
        }
        return res;
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends