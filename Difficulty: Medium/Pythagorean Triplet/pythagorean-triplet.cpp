class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_set<int> st;
        for(auto i:arr) st.insert(i*i);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i] * arr[i] + arr[j] * arr[j];
                if (st.count(sum)) {
                    return true;
                }
            }
        }
        return false;
    }
};