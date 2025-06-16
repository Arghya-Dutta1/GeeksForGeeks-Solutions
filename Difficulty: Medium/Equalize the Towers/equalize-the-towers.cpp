class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();
        vector<pair<int, int>> tower(n);
        for (int i = 0; i < n; ++i)
            tower[i] = {heights[i], cost[i]};
        sort(tower.begin(), tower.end());
        long long totalCost = 0;
        for (int i = 0; i < n; ++i)
            totalCost += tower[i].second;
        long long prefixCost = 0;
        int targetHeight = 0;
        for (int i = 0; i < n; ++i) {
            prefixCost += tower[i].second;
            if (prefixCost >= (totalCost + 1) / 2) {
                targetHeight = tower[i].first;
                break;
            }
        }
        long long minTotalCost = 0;
        for (int i = 0; i < n; ++i)
            minTotalCost += 1LL * abs(tower[i].first - targetHeight) * tower[i].second;
        return minTotalCost;
    }
};
