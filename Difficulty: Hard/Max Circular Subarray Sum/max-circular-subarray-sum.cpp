//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int tsum=0, cmxsum=0, cmnsum=0, mxsum=INT_MIN, mnsum=INT_MAX;
        for(auto i:arr){
            tsum+=i;
            cmxsum=max(cmxsum+i, i);
            cmnsum=min(cmnsum+i, i);
            mxsum=max(mxsum, cmxsum);
            mnsum=min(mnsum, cmnsum);
        }
        return mxsum<0?mxsum:max(mxsum, tsum-mnsum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends