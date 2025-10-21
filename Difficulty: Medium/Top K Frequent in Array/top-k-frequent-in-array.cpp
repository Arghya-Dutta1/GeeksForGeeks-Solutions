class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;
        vector<pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;  
        });

        vector<int> ans;
        for (int i = 0; i < k && i < vec.size(); i++)
            ans.push_back(vec[i].first);

        return ans;
    }
};
