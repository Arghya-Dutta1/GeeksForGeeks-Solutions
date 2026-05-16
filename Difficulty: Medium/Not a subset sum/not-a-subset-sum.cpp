class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        int ans = 1;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > ans)
                return ans;

            ans += arr[i];
        }

        return ans;
    }
};