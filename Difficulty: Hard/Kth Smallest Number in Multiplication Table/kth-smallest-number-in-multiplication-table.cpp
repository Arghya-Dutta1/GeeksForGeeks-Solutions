class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) cnt += min(mid / i, n);
            if (cnt >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
