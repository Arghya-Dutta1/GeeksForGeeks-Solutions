class Solution {
  public:
    bool isPossible(vector<int>& nums, int k) {
        int n = nums.size();
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        int i = 0;
        while (i < n) {
            if (pq.empty()) {
                pq.push({nums[i], 1});
                i++;
            } 
            else {
                auto current = pq.top();

                if (nums[i] == current.first) {
                    pq.push({nums[i], 1});
                    i++;
                } 
                else if (nums[i] == current.first + 1) {
                    pq.pop();
                    pq.push({nums[i], current.second + 1});
                    i++;
                } 
                else {
                    if (current.second < k) return false;
                    pq.pop();
                }
            }
        }
        while (!pq.empty()) {
            if (pq.top().second < k) return false;
            pq.pop();
        }

        return true;
    }
};