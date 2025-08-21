class Solution {
  public:
    bool canPlace(vector<int>& arr, int k, int diff) {
        int count = 1, lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= diff) {
                count++;
                lastPlaced = arr[i];
            }
            if (count >= k) return true;
        }
        return false;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 0, high = arr.back() - arr.front(), result = 0;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (canPlace(arr, k, mid)) {
                result = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return result;
    }
};