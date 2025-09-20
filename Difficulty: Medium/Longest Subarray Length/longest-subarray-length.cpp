class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextGreater(n, n), prev(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int len = nextGreater[i] - prev[i] - 1;
            if (arr[i] <= len) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
