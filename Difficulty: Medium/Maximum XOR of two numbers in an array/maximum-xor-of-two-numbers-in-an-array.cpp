//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &nums) {
        // code here
        int maxNum=*max_element(nums.begin(), nums.end());
        if(maxNum==0) return 0;

        int maxBit=static_cast<int>(log2(maxNum));
        int ans=0, mask=0;

        for(int i=maxBit; i>=0; i--){
            mask|=1<<i;
            unordered_set<int> prefixes;

            for(int num:nums)
                prefixes.insert(num&mask);

            int candidate=ans|(1<<i);
            for(int prefix:prefixes)
                if (prefixes.count(prefix^candidate)){
                    ans=candidate;
                    break;
                }
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends