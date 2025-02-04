//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& nums) {
        // complete the function here
        int l=0, r=nums.size()-1;
        while(l<r){
            int m=(l+r)/2;
            if(nums[m]>nums[r])
                l=m+1;
            else if(nums[m]<nums[r])
                r=m;
            else
                r--;
        }
        return nums[l];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends