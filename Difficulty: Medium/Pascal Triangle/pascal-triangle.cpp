//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
            ans.push_back(vector<int>(i+1, 1));

        for(int i=2; i<n; i++)
            for(int j=1; j<ans[i].size()-1; j++)
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];

        return ans[n-1];
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends