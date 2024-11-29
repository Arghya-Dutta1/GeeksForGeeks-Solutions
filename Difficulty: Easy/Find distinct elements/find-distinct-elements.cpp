//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
int distinct(vector<int>& arr) {
    // Your code here
    set<int> st;
    for(auto i:arr) st.insert(i);
    return st.size();
}

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cout << distinct(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends