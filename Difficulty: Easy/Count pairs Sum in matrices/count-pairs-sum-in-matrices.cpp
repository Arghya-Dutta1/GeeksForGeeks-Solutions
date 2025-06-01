class Solution {
  public:
    int countPairs(vector<vector<int>> &m1, vector<vector<int>> &m2, int x) {
        // code here
        unordered_set<int> s1, s2;
        for(auto& i:m1)
            for(auto j:i)
                s1.insert(j);
        for(auto& i:m2)
            for(auto j:i)
                s2.insert(j);
        int ans=0;
        for(auto it:s1){
            int cmp=x-it;
            if(s2.count(cmp))
                ans++;
        }
        return ans;
    }
};