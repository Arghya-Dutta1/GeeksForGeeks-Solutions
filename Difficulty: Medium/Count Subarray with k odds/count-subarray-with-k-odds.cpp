class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // base case
        
        int oddCnt = 0;
        int ans = 0;
        
        for (int x : arr) {
            if (x % 2 == 1) oddCnt++;
            
            if (mp.count(oddCnt - k)) {
                ans += mp[oddCnt - k];
            }
            
            mp[oddCnt]++;
        }
        
        return ans;
    }
};
