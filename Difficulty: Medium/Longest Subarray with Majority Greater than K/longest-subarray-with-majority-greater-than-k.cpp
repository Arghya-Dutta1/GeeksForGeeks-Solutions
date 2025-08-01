class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = (arr[i] > k) ? 1 : -1;

        unordered_map<int, int> firstSeen;
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += mapped[i];

            if (prefixSum > 0) {
                maxLen = i + 1;
            } else {
                if (firstSeen.find(prefixSum - 1) != firstSeen.end()) {
                    maxLen = max(maxLen, i - firstSeen[prefixSum - 1]);
                }
            }

            if (firstSeen.find(prefixSum) == firstSeen.end()) 
                firstSeen[prefixSum] = i;
        }
        return maxLen;
    }
};