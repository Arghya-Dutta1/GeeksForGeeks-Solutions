//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int atMostK(vector<int> &nums, int k) {
        // code here
        int ans=0;
        vector<int> count(nums.size()+1);

        for(int l=0,r=0;r<nums.size();r++){
            if(++count[nums[r]]==1)
                k--;
            while(k==-1)
                if(--count[nums[l++]]==0)
                    k++;
            ans+=r-l+1;
        }
        return ans;
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.atMostK(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends