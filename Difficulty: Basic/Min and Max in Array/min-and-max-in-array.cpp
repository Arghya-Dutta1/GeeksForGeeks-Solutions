// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int mn=*min_element(arr.begin(), arr.end()), mx=*max_element(arr.begin(), arr.end());
        return {mn,mx};
    }
};