class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        map<int, int> mp;
        vector<int> ans;
        int n=arr.size()/3;
        for(auto i:arr) mp[i]++;
        for(auto i:mp)
            if(i.second>n)
                ans.push_back(i.first);
        return ans;
    }
};