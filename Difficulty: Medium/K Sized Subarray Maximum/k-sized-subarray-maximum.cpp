//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        vector<int> ans;
        deque<vector<int>> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.back()[0]<=nums[i]){
                dq.pop_back();
            }
            while(!dq.empty() && dq.front()[1]<i-k+1){
                dq.pop_front();
            }
            dq.push_back({nums[i],i});
            if(i>=k-1){
                ans.push_back(dq.front()[0]);
            }
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends