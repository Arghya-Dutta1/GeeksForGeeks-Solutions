class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> solve(int idx, vector<int>& arr, int prev_idx) {
        if (idx == arr.size())
            return {};
        if (dp[idx][prev_idx + 1].size() > 0)
            return dp[idx][prev_idx + 1];
        vector<int> taken;
        if (prev_idx == -1 || arr[idx] % arr[prev_idx] == 0) {
            taken = solve(idx + 1, arr, idx);     
            taken.insert(taken.begin(), arr[idx]); 
        }
        vector<int> not_take = solve(idx + 1, arr, prev_idx); 
        vector<int> result = (not_take.size() > taken.size() || (not_take.size() == taken.size() && not_take > taken))
                              ? not_take : taken;
        return dp[idx][prev_idx + 1] = result;
    }
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1));
        return solve(0, arr, -1);
    }
};